#include "battle_scene.hpp"

// TODO factory
#include "assets/level_interface.hpp"
#include "components/position_component.hpp"
#include "components/sprite_component.hpp"

namespace
{
void create_debug_entity(entt::registry& registry)
{
    auto entity = registry.create();
    registry.emplace<game::comp::Position>(entity, 100, 100);
    registry.emplace<game::comp::Sprite>(entity, renderer::Sprite_id::Rectangle_red);
}
}  // namespace

namespace game
{
Battle_scene::Battle_scene(entt::registry& registry) : Scene(registry)
{
    create_debug_entity(registry);
}

void Battle_scene::init(const Level& level)
{
    // TODO do something
}

const std::string& Battle_scene::get_level_id()
{
    return m_level.get_id();
}

void Battle_scene::dispose()
{
}

}  // namespace game