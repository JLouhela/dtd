#include "enemy_spawn_system.hpp"

namespace game
{
namespace sys
{

void Enemy_spawner::set_level(const Level* level)
{
    m_level = level;
    if (m_level)
    {
        init_wave_states();
    }
}

void Enemy_spawner::spawn_enemies(entt::registry& reg, std::uint32_t delta_time)
{
    if (!m_level)
    {
        return;
    }
    /*
    struct Wave_state
{
    Waves::const_iterator current_wave;
    math::Float_vector spawn_point{0, 0};
    std::uint32_t spawned_count{0};
    std::chrono::time_point<std::chrono::system_clock> last_spawn_time;
};
*/
}

void Enemy_spawner::init_wave_states()
{
    m_wave_states.clear();

    const auto& waypoints = m_level->get_waypoints();
    const auto& waves = m_level->get_waves();
    for (const auto& waypoint_vector : waypoints)
    {
        m_wave_states.emplace_back(waves.cbegin(), waypoint_vector.waypoints.front().point);
    }
}

}  // namespace sys
}  // namespace game