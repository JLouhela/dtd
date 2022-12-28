#include "waypoint_follow_system.hpp"

#include "../components/direction_component.hpp"

namespace game::sys
{
void update_entity_waypoints(entt::registry& reg)
{
}

void update_entity_directions(entt::registry& reg)
{
    const auto view = reg.view<comp::Direction>();
    for (const entt::entity e : view)
    {
        auto& dir = reg.get<comp::Direction>(e);
    }
}
}  // namespace game::sys