#include <chrono>
#include <cstdint>
#include <memory>

#include "entt/entt.hpp"
#include "level.hpp"

namespace game
{
namespace sys
{

using Waves = std::vector<assets::level::Enemy_wave>;
struct Wave_state
{
    Wave_state(Waves::const_iterator wave_start, Waves::const_iterator end_wave, std::int8_t spawn_index)
        : current_wave{std::move(wave_start)}, end_wave{end_wave}, spawn_index{spawn_index}
    {
        const auto enemy_count = wave_start->enemies.size();
        spawned_counts = std::vector<std::uint32_t>(enemy_count, 0);
        remaining_spawn_times = std::vector<float>(enemy_count, 0);
    }
    Waves::const_iterator current_wave;
    Waves::const_iterator end_wave;
    std::int8_t spawn_index{-1};
    std::vector<std::uint32_t> spawned_counts;  // Corresponds to amount of different enemies in wave
    std::vector<float> remaining_spawn_times;   // Corresponds to amount of different enemies in wave
};

class Enemy_spawn_system
{
public:
    void set_level(std::weak_ptr<Level> level);
    void spawn_enemies(entt::registry& reg, float delta_time);
    void prepare_next_wave();

private:
    void init_wave_states(const Level& level);

    std::vector<Wave_state> m_wave_states;
    std::weak_ptr<Level> m_level;
};

}  // namespace sys
}  // namespace game