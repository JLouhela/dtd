#include "battle_scene.hpp"

#include "../entities/entity_factory.hpp"
#include "../systems/debug_render_system.hpp"
#include "../systems/movement_system.hpp"
#include "../systems/render_system.hpp"
#include "assets/level_interface.hpp"
#include "renderer/renderer_interface.hpp"

namespace game
{
Battle_scene::Battle_scene(entt::registry& registry, renderer::Renderer_interface& renderer) : Scene(registry, renderer)
{
    entity::factory::create_debug_entity(registry);
}

void Battle_scene::init(const assets::level::Level_interface& level_content)
{
    m_level = std::make_shared<Level>(level_content);
    m_enemy_spawner.set_level(m_level);
    m_waypoint_system.set_level(m_level);
}

std::string Battle_scene::get_level_id()
{
    return m_level ? m_level->get_id() : "undefined";
}

void Battle_scene::dispose()
{
    m_enemy_spawner.set_level(std::weak_ptr<Level>());
}

void Battle_scene::update(std::int32_t delta_time)
{
    // TODO handle states properly
    m_state = Battle_state::SPAWN;
    if (m_state == Battle_state::SPAWN)
    {
        m_enemy_spawner.spawn_enemies(m_registry, delta_time);
    }
    m_waypoint_system.update_entity_waypoints(m_registry);
    m_waypoint_system.update_entity_directions(m_registry);
    sys::Movement_system::move_entities(m_registry, delta_time);
    execute_renderers();
}

void Battle_scene::execute_renderers()
{
#ifdef DEBUG
    sys::debug::Render_system::render_grid(m_renderer.get_debug_renderer());
#endif
    sys::Render_system::render_level(m_renderer.get_level_renderer());
    sys::Render_system::render_sprites(m_registry, m_renderer.get_sprite_renderer());

    // TODO hook to events
    const bool display_hud = false;
    if (display_hud)
    {
        sys::Render_system::render_hud(m_renderer.get_hud_renderer());
    }
}

}  // namespace game