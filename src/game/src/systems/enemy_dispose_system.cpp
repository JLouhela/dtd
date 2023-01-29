#include "enemy_dispose_system.hpp"

#include "../components/enemy_component.hpp"
#include "../components/health_component.hpp"

namespace game
{
namespace sys::Enemy_dispose_system
{

void dispose_enemies_by_health(entt::registry& reg)
{
    const auto view = reg.view<comp::Enemy, comp::Health>();
    const entt::registry& creg = reg;
    for (const entt::entity e : view)
    {
        const auto& health = creg.get<comp::Health>(e);
        if (health.health <= 0.0f)
        {
            reg.destroy(e);
        }
    }
}

}  // namespace sys::Enemy_dispose_system
}  // namespace game