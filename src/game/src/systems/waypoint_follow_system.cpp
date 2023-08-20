#include "waypoint_follow_system.hpp"

#include <cmath>

#include "../components/direction_component.hpp"
#include "../components/position_component.hpp"
#include "../components/waypoint_follower_component.hpp"
#include "loguru/loguru.hpp"

namespace game::sys
{
void Waypoint_follow_system::update_entity_waypoints(entt::registry& reg)
{
    if (const auto level = m_level.lock())
    {
        const auto view = reg.view<comp::Position, comp::Waypoint_follower>();
        const entt::registry& creg = reg;
        for (const entt::entity e : view)
        {
            const auto& pos = creg.get<comp::Position>(e);
            auto& waypoint = reg.get<comp::Waypoint_follower>(e);

            static constexpr float WAYPOINT_SWITCH_DISTANCE = 1.0f;
            const auto& waypoints = level->get_waypoints()[waypoint.spawn_index].waypoints;
            if (waypoints.size() <= static_cast<size_t>(waypoint.waypoint_index))
            {
                continue;
            }
            const auto& target = waypoints[waypoint.waypoint_index].point;
            const math::Float_vector direction{target.x - pos.x, target.y - pos.y};
            const float distance_to_target = std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));
            if (distance_to_target < WAYPOINT_SWITCH_DISTANCE)
            {
                waypoint.waypoint_index++;
            }
        }
    }
}

void Waypoint_follow_system::set_level(std::weak_ptr<Level> level)
{
    m_level = level;
}

void Waypoint_follow_system::update_entity_directions(entt::registry& reg)
{
    if (const auto level = m_level.lock())
    {
        const auto view = reg.view<comp::Direction, comp::Position, comp::Waypoint_follower>();
        const entt::registry& creg = reg;
        for (const entt::entity e : view)
        {
            auto& direction = reg.get<comp::Direction>(e);
            const auto& pos = creg.get<comp::Position>(e);
            const auto& waypoint = creg.get<comp::Waypoint_follower>(e);

            const auto& waypoints = level->get_waypoints()[waypoint.spawn_index].waypoints;
            if (waypoints.size() <= static_cast<size_t>(waypoint.waypoint_index))
            {
                continue;
            }
            const auto& target = waypoints[waypoint.waypoint_index].point;
            const math::Float_vector dir{target.x - pos.x, target.y - pos.y};
            const float length = std::sqrt(std::pow(dir.x, 2) + std::pow(dir.y, 2));
            direction.x = dir.x / length;
            direction.y = dir.y / length;
        }
    }
}
}  // namespace game::sys