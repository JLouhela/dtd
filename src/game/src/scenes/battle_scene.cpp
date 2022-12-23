#include "battle_scene.hpp"

#include "renderer/renderer_interface.hpp"

// TODO factory
#include "../systems/debug_render_system.hpp"
#include "../systems/render_system.hpp"
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
Battle_scene::Battle_scene(entt::registry& registry, renderer::Renderer_interface& renderer) : Scene(registry, renderer)
{
    create_debug_entity(registry);
}

void Battle_scene::init(const Level& level)
{
    m_level = &level;
    m_enemy_spawner.set_level(&level);
}

std::string Battle_scene::get_level_id()
{
    return m_level ? m_level->get_id() : "undefined";
}

void Battle_scene::dispose()
{
    m_enemy_spawner.set_level(nullptr);
}

void Battle_scene::update(std::int32_t delta_time)
{
    if (m_state == Battle_state::SPAWN)
    {
        m_enemy_spawner.spawn_enemies(m_registry, delta_time);
    }
    execute_renderers();
}

void Battle_scene::execute_renderers()
{
#ifdef DEBUG
    sys::debug::render_grid(m_renderer.get_debug_renderer());
#endif
    sys::render_level(m_renderer.get_level_renderer());
    sys::render_sprites(m_registry, m_renderer.get_sprite_renderer());

    // TODO hook to events
    const bool display_hud = false;
    if (display_hud)
    {
        sys::render_hud(m_renderer.get_hud_renderer());
    }
}

}  // namespace game