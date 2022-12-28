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
    static bool flag = true;
    if (flag)
    {
        LOG_F(WARNING, "Waypoint_follow_system::update_entity_waypoints not implemented!");
        flag = false;
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

            const auto& target = level->get_waypoints()[waypoint.spawn_index].waypoints[waypoint.waypoint_index].point;
            const math::Float_vector dir{target.x - pos.x, target.y - pos.y};
            const float length_to_target = std::sqrt(std::powf(target.x, 2) + std::powf(target.y, 2));
            direction.dir = {dir.x / length_to_target, dir.y / length_to_target};
        }
    }
}
}  // namespace game::sys