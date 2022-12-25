#include "enemy_spawn_system.hpp"

namespace
{

bool all_waves_spawned(const game::sys::Wave_state& wave_state)
{
    return wave_state.current_wave == wave_state.end_wave;
}

bool need_spawn(const game::sys::Wave_state& wave_state)
{
    if (all_waves_spawned(wave_state))
    {
        return false;
    }

    for (std::uint32_t i = 0; i < wave_state.current_wave->enemies.size(); ++i)
    {
        const auto& enemies = wave_state.current_wave->enemies[i];
        if (wave_state.spawned_counts[i] >= enemies.count)
        {
            continue;
        }
        if (wave_state.remaining_spawn_times[i] <= 0)
        {
            return true;
        }
    }
    return false;
}

void update_spawn_times(game::sys::Wave_state& wave_state, const std::uint32_t delta_time)
{
    for (auto& spawn_time : wave_state.remaining_spawn_times)
    {
        spawn_time -= static_cast<std::int32_t>(delta_time);
    }
}

void spawn_enemies(game::sys::Wave_state& wave_state, entt::registry& reg)
{
}

void progress_state(game::sys::Wave_state& wave_state)
{
    for (std::uint32_t i = 0; i < wave_state.current_wave->enemies.size(); ++i)
    {
        auto& spawn_time = wave_state.remaining_spawn_times[i];
        if (spawn_time <= 0)
        {
            spawn_time = wave_state.current_wave->enemies[i].spawn_time;
        }
    }
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
        wave_state.remaining_spawn_times = std::vector<std::int32_t>(enemy_count, 0);
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
        update_spawn_times(wave_state, delta_time);
        if (!need_spawn(wave_state))
        {
            continue;
        }
        ::spawn_enemies(wave_state, reg);
        progress_state(wave_state);
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