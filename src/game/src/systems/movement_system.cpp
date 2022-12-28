#include "movement_system.hpp"

#include "../components/direction_component.hpp"
#include "../components/position_component.hpp"
#include "../components/speed_component.hpp"
#include "loguru/loguru.hpp"

namespace game
{
namespace sys::Movement_system
{
void move_entities(entt::registry& reg, const float dt)
{
    // LOG_F(INFO, "dt = %d", dt);
    const auto view = reg.view<comp::Direction, comp::Position, comp::Speed>();
    const entt::registry& creg = reg;
    for (const entt::entity e : view)
    {
        const auto& direction = creg.get<comp::Direction>(e);
        const auto& speed = creg.get<comp::Speed>(e);
        auto& pos = reg.get<comp::Position>(e);

        // Scale speed 1.0f to sensible number
        static constexpr float SPEED_MULTIPLIER = 50.0f;
        pos.x += (direction.x * speed.speed * dt * SPEED_MULTIPLIER);
        pos.y += (direction.y * speed.speed * dt * SPEED_MULTIPLIER);
    }
}

}  // namespace sys::Movement_system
}  // namespace game