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
    void set_level(std::weak_ptr<Level> level);

private:
    std::weak_ptr<Level> m_level;
};

}  // namespace game::sys