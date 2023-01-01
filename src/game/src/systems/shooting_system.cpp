#include "shooting_system.hpp"

#include "../components/enemy_component.hpp"
#include "../components/enemy_shooter_component.hpp"
#include "../components/position_component.hpp"
#include "../entities/entity_factory.hpp"
#include "loguru/loguru.hpp"

namespace game
{
namespace sys::Shooting_system
{
void shoot_enemies(entt::registry& reg, float dt)
{
    const auto view = reg.view<comp::Enemy_shooter, comp::Position>();
    const entt::registry& creg = reg;
    for (const entt::entity e : view)
    {
        auto& shooter = reg.get<comp::Enemy_shooter>(e);
        if (shooter.target_id == comp::INVALID_TARGET_ID)
        {
            continue;
        }

        shooter.shooting_time -= dt;
        if (shooter.shooting_time > 0.0f)
        {
            continue;
        }
        const auto& shooter_pos = creg.get<comp::Position>(e);
        const auto enemy = entt::entity{shooter.target_id};
        // Check existence of component / entity? Depends on how entities will be disposed.
        const auto& enemy_pos = creg.get<comp::Position>(enemy);
        // TODO take speed, dir into account (when rendering projectiles)
        shooter.shooting_time = shooter.shooting_delay;
        // TODO get values from.. somewhere
        entity::factory::create_projectile(reg, "basic", {shooter_pos.x, shooter_pos.y}, {enemy_pos.x, enemy_pos.y},
                                           50.0f, 10.0f);
    }
}

}  // namespace sys::Shooting_system
}  // namespace game