#include <chrono>
#include <cstdint>

#include "entt/entt.hpp"
#include "level.hpp"

namespace game
{
namespace sys
{

class Enemy_spawner
{
public:
    void set_level(const Level* level);
    void spawn_enemies(entt::registry& reg, std::uint32_t delta_time);

private:
    void init_wave_states();

    using Waves = std::vector<assets::level::Enemy_wave>;
    struct Wave_state
    {
        Wave_state(Waves::const_iterator wave_start, math::Float_vector spawn_point)
            : current_wave{std::move(wave_start)}, spawn_point{std::move(spawn_point)}
        {
        }
        Waves::const_iterator current_wave;
        math::Float_vector spawn_point{0, 0};
        std::uint32_t spawned_count{0};
        std::chrono::time_point<std::chrono::system_clock> last_spawn_time;
    };

    std::vector<Wave_state> m_wave_states;
    const Level* m_level{nullptr};
};

}  // namespace sys
}  // namespace game