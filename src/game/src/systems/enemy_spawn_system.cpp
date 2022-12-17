#include "enemy_spawn_system.hpp"

namespace game
{
namespace sys
{

void Enemy_spawner::set_level(const Level* level)
{
    m_level = level;
}

void Enemy_spawner::spawn_enemies(entt::registry& reg, std::uint32_t delta_time)
{
    // TODO maintain state: which wave going on
}

}  // namespace sys
}  // namespace game