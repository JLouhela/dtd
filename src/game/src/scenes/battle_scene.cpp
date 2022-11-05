#include "battle_scene.hpp"

namespace game
{
Battle_scene::Battle_scene(entt::registry& registry) : Scene(registry)
{
}

void Battle_scene::init(const std::string& level)
{
    m_level.load(level);
}

const std::string& Battle_scene::get_level_id()
{
    return m_level.get_id();
}

void Battle_scene::dispose()
{
}

}  // namespace game