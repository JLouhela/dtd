#include "battle_scene.hpp"

// TODO factory
#include "components/position_component.hpp"

namespace
{
void create_debug_entity(entt::registry& registry)
{
    auto entity = registry.create();
    registry.emplace<game::comp::Position>(entity, 0, 0);
}
}  // namespace

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