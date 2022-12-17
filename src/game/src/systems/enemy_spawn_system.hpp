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
    const Level* m_level{nullptr};
};

}  // namespace sys
}  // namespace game