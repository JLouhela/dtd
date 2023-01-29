#include "targeting_system.hpp"

#include <cmath>
#include <limits>

#include "../components/circle_radius_component.hpp"
#include "../components/enemy_component.hpp"
#include "../components/enemy_shooter_component.hpp"
#include "../components/position_component.hpp"
#include "loguru/loguru.hpp"
#include "types/entity_id.hpp"

namespace game
{
namespace sys::Targeting_system
{

void acquire_targets(entt::registry& reg)
{
    const auto shooter_view = reg.view<comp::Circle_radius, comp::Position, comp::Enemy_shooter>();
    const auto enemy_view = reg.view<comp::Position, comp::Enemy>();
    const entt::registry& creg = reg;
    for (const entt::entity shooter_entity : shooter_view)
    {
        auto& shooter_shooter = reg.get<comp::Enemy_shooter>(shooter_entity);
        if (shooter_shooter.target_id != types::Invalid_entity_id)
        {
            // Already has target
            continue;
        }
        const auto& shooter_pos = creg.get<comp::Position>(shooter_entity);
        const auto& shooter_radius = creg.get<comp::Circle_radius>(shooter_entity);

        float distance = std::numeric_limits<float>::max();
        entt::entity target = entt::null;
        for (const entt::entity enemy_entity : enemy_view)
        {
            const auto& enemy_pos = creg.get<comp::Position>(enemy_entity);
            const auto dx = shooter_pos.x - enemy_pos.x;
            const auto dy = shooter_pos.y - enemy_pos.y;
            const auto distance_tmp = std::sqrt(std::powf(dx, 2) + std::powf(dy, 2));
            if (distance_tmp < shooter_radius.radius && distance_tmp < distance)
            {
                distance = distance_tmp;
                target = enemy_entity;
            }
        }
        if (target != entt::null)
        {
            shooter_shooter.target_id = static_cast<std::uint32_t>(target);
        }
    }
}

void release_targets(entt::registry& reg)
{
    const auto shooter_view = reg.view<comp::Circle_radius, comp::Position, comp::Enemy_shooter>();
    const entt::registry& creg = reg;
    for (const entt::entity shooter_entity : shooter_view)
    {
        auto& shooter_shooter = reg.get<comp::Enemy_shooter>(shooter_entity);
        if (shooter_shooter.target_id == types::Invalid_entity_id)
        {
            // No target
            continue;
        }
        if (!reg.valid(static_cast<entt::entity>(shooter_shooter.target_id)))
        {
            shooter_shooter.target_id = types::Invalid_entity_id;
            continue;
        }
        const auto& shooter_pos = creg.get<comp::Position>(shooter_entity);
        const auto& shooter_radius = creg.get<comp::Circle_radius>(shooter_entity);

        const auto& enemy_pos = creg.get<comp::Position>(entt::entity{shooter_shooter.target_id});
        const auto dx = shooter_pos.x - enemy_pos.x;
        const auto dy = shooter_pos.y - enemy_pos.y;
        const auto distance = std::sqrt(std::powf(dx, 2) + std::powf(dy, 2));
        if (distance > shooter_radius.radius)
        {
            shooter_shooter.target_id = types::Invalid_entity_id;
        }
    }
}

}  // namespace sys::Targeting_system
}  // namespace game