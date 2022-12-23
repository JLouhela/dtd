#include "enemy_spawn_system.hpp"

namespace
{

bool all_waves_spawned(const game::sys::Wave_state& wave_state)
{
    return true;
}

bool all_enemies_spawned(const game::sys::Wave_state& wave_state)
{
    return true;
}

bool all_spawned(const game::sys::Wave_state& wave_state)
{
    return all_waves_spawned(wave_state) && all_enemies_spawned(wave_state);
}
bool time_to_spawn(const game::sys::Wave_state& wave_state)
{
    return false;
}

void spawn_enemy(game::sys::Wave_state& wave_state, entt::registry& reg)
{
}

void update_state(game::sys::Wave_state& wave_state, const std::uint32_t delta_time)
{
}

}  // namespace

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

void Enemy_spawner::prepare_next_wave()
{
    for (auto& wave_state : m_wave_states)
    {
        wave_state.current_wave++;
        if (wave_state.current_wave == wave_state.end_wave)
        {
            continue;
        }
        const auto enemy_count = wave_state.current_wave->enemies.size();
        // Heap allocation, bad!
        wave_state.last_spawn_times = std::vector<std::uint32_t>(enemy_count, 0);
        wave_state.spawned_counts = std::vector<std::uint32_t>(enemy_count, 0);
    }
}

void Enemy_spawner::spawn_enemies(entt::registry& reg, std::uint32_t delta_time)
{
    if (!m_level)
    {
        return;
    }
    for (auto& wave_state : m_wave_states)
    {
        if (all_spawned(wave_state))
        {
            continue;
        }
        if (!time_to_spawn(wave_state))
        {
            continue;
        }
        spawn_enemy(wave_state, reg);
        update_state(wave_state, delta_time);
    }
}

void Enemy_spawner::init_wave_states()
{
    m_wave_states.clear();

    const auto& waypoints = m_level->get_waypoints();
    const auto& waves = m_level->get_waves();
    for (const auto& waypoint_vector : waypoints)
    {
        m_wave_states.emplace_back(std::cbegin(waves), std::cend(waves), waypoint_vector.waypoints.front().point);
    }
}

}  // namespace sys
}  // namespace game