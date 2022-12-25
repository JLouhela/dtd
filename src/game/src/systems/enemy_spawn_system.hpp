#include <chrono>
#include <cstdint>

#include "entt/entt.hpp"
#include "level.hpp"

namespace game
{
namespace sys
{

using Waves = std::vector<assets::level::Enemy_wave>;
struct Wave_state
{
    Wave_state(Waves::const_iterator wave_start, Waves::const_iterator end_wave, math::Float_vector spawn_point)
        : current_wave{std::move(wave_start)}, end_wave{end_wave}, spawn_point{std::move(spawn_point)}
    {
        const auto enemy_count = wave_start->enemies.size();
        spawned_counts = std::vector<std::uint32_t>(enemy_count, 0);
        remaining_spawn_times = std::vector<std::int32_t>(enemy_count, 0);
    }
    Waves::const_iterator current_wave;
    Waves::const_iterator end_wave;
    math::Float_vector spawn_point{0.f, 0.f};
    std::vector<std::uint32_t> spawned_counts;        // Corresponds to amount of different enemies in wave
    std::vector<std::int32_t> remaining_spawn_times;  // Corresponds to amount of different enemies in wave
};

class Enemy_spawner
{
public:
    void set_level(const Level* level);
    void spawn_enemies(entt::registry& reg, std::uint32_t delta_time);
    void prepare_next_wave();

private:
    void init_wave_states();

    std::vector<Wave_state> m_wave_states;
    const Level* m_level{nullptr};
};

}  // namespace sys
}  // namespace game