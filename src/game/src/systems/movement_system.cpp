#include "movement_system.hpp"

#include "../components/direction_component.hpp"
#include "../components/position_component.hpp"
#include "../components/velocity_component.hpp"
#include "loguru/loguru.hpp"

namespace game
{
namespace sys::Movement_system
{
void move_entities(entt::registry& reg, const float dt)
{
    const auto view = reg.view<comp::Direction, comp::Position, comp::Velocity>();
    const entt::registry& creg = reg;
    for (const entt::entity e : view)
    {
        const auto& direction = creg.get<comp::Direction>(e);
        const auto& velocity = creg.get<comp::Velocity>(e);
        auto& pos = reg.get<comp::Position>(e);

        // Scale speed 1.0f to sensible number
        static constexpr float SPEED_MULTIPLIER = 50.0f;
        pos.x += (direction.x * velocity.velocity * dt * SPEED_MULTIPLIER);
        pos.y += (direction.y * velocity.velocity * dt * SPEED_MULTIPLIER);
    }
}

}  // namespace sys::Movement_system
}  // namespace game