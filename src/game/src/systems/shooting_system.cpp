#include "shooting_system.hpp"

#include "../components/enemy_component.hpp"
#include "../components/enemy_shooter_component.hpp"
#include "../components/position_component.hpp"
#include "loguru/loguru.hpp"

namespace game
{
namespace sys::Shooting_system
{
void shoot_enemies(entt::registry& reg, float dt)
{
    const auto view = reg.view<comp::Enemy_shooter>();
    const entt::registry& creg = reg;
    for (const entt::entity e : view)
    {
        auto& shooter = reg.get<comp::Enemy_shooter>(e);
        if (shooter.target_id == comp::INVALID_TARGET_ID)
        {
            continue;
        }

        shooter.shooting_time -= dt;
        if (shooter.shooting_time > 0.0f)
        {
            continue;
        }

        const auto enemy = entt::entity{shooter.target_id};
        // Check existence of component / entity? Depends on how entities will be disposed.
        const auto& enemy_pos = creg.get<comp::Position>(enemy);
        // TODO take speed, dir into account (when rendering projectiles)
        // TODO fire projectiles -> inflict damage
        LOG_F(INFO, "FIRE: (%f, %f)", enemy_pos.x, enemy_pos.y);
        shooter.shooting_time = shooter.shooting_delay;
    }
}

}  // namespace sys::Shooting_system
}  // namespace game