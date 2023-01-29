#include "projectile_system.hpp"

#include "../components/position_component.hpp"
#include "../components/projectile_component.hpp"
#include "../entities/entity_factory.hpp"
#include "loguru/loguru.hpp"
#include "math/algorithm.hpp"
#include "math/vector.hpp"

namespace game
{
namespace sys::Projectile_system
{

static constexpr float HIT_DISTANCE = 1.0f;

void destroy_projectiles(entt::registry& reg)
{
    const auto view = reg.view<comp::Position, comp::Position, comp::Projectile>();
    const entt::registry& creg = reg;
    for (const entt::entity e : view)
    {
        const auto& pos = creg.get<comp::Position>(e);
        const auto projectile_pos = math::Float_vector{pos.x, pos.y};

        auto& projectile = reg.get<comp::Projectile>(e);
        const auto& target_pos = projectile.target_pos;
        auto& prev_projectile_pos = projectile.prev_pos;

        const float len_projectile_target = math::direction<math::Float_vector>(projectile_pos, target_pos).length();

        const float len_prev_projectile_target =
            math::direction<math::Float_vector>(projectile.prev_pos, target_pos).length();

        const float len_prev_projectile_cur =
            math::direction<math::Float_vector>(projectile_pos, projectile.prev_pos).length();

        const float cumulative_projectile_dist = len_projectile_target + len_prev_projectile_target;

        // Check if target_point is between  previous and next point
        const bool hit = math::float_eq(cumulative_projectile_dist, len_prev_projectile_cur, HIT_DISTANCE);

        prev_projectile_pos.x = projectile_pos.x;
        prev_projectile_pos.y = projectile_pos.y;

        if (hit)
        {
            // TODO define which kind of hit, e.g. aoe?
            // TODO store radius to projectile
            // TODO there is a very high risk to hit wrong enemy currently, mvp
            static constexpr float radius = 10.0f;
            entity::factory::create_hit(reg, projectile.type, target_pos, projectile.damage, radius);
            reg.destroy(e);
        }
    }
}

}  // namespace sys::Projectile_system
}  // namespace game