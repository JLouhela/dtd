#pragma once
#include "entt/entt.hpp"
#include "level.hpp"

namespace game::sys
{
class Waypoint_follow_system
{
public:
    void update_entity_waypoints(entt::registry& reg);
    void update_entity_directions(entt::registry& reg);
    void set_waypoints(const std::vector<assets::level::Waypoints>& waypoints)
    {
        m_waypoints = &waypoints;
    }

private:
    const std::vector<assets::level::Waypoints>* m_waypoints{nullptr};
};

}  // namespace game::sys