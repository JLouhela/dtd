#include "damage_system.hpp"

#include <algorithm>
#include <vector>

#include "../components/damage_component.hpp"
#include "../components/enemy_component.hpp"
#include "../components/health_component.hpp"
#include "../components/position_component.hpp"
#include "math/algorithm.hpp"
#include "types/entity_id.hpp"

namespace game
{
namespace sys::Damage_system
{

void deal_damage(entt::registry& reg)
{
    const auto damage_view = reg.view<comp::Damage, comp::Position>();
    const auto enemy_view = reg.view<comp::Enemy, comp::Position, comp::Health>();
    const entt::registry& creg = reg;
    for (const entt::entity damage_entity : damage_view)
    {
        const auto& damage = creg.get<comp::Damage>(damage_entity);
        const auto& damage_pos = creg.get<comp::Position>(damage_entity);
        std::vector<entt::entity> hits;
        std::copy_if(enemy_view.begin(), enemy_view.end(), std::back_inserter(hits),
                     [&creg, &damage, &damage_pos](entt::entity enemy)
                     {
                         // TODO consider enemy bounds instead of center?
                         const auto& enemy_pos = creg.get<comp::Position>(enemy);
                         return math::float_eq(damage_pos.x, enemy_pos.x, damage.radius) &&
                                math::float_eq(damage_pos.y, enemy_pos.y, damage.radius);
                     });
        for (const auto& hit : hits)
        {
            auto& hp = reg.get<comp::Health>(hit);
            hp.health -= damage.damage;
        }
        reg.remove<comp::Damage>(damage_entity);
    }
}

}  // namespace sys::Damage_system
}  // namespace game