#include "movement_system.hpp"

#include "../components/direction_component.hpp"
#include "../components/position_component.hpp"
#include "../components/speed_component.hpp"
#include "loguru/loguru.hpp"

namespace game
{
namespace sys::Movement_system
{
void move_entities(entt::registry& reg, const std::int32_t dt)
{
    // LOG_F(INFO, "dt = %d", dt);
    const auto view = reg.view<comp::Direction, comp::Position, comp::Speed>();
    const entt::registry& creg = reg;
    for (const entt::entity e : view)
    {
        const auto& direction = creg.get<comp::Direction>(e);
        const auto& speed = creg.get<comp::Speed>(e);
        auto& pos = reg.get<comp::Position>(e);
        pos.x += (direction.x * speed.speed * dt);
        pos.y += (direction.y * speed.speed * dt);
    }
}

}  // namespace sys::Movement_system
}  // namespace game