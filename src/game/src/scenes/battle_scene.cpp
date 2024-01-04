#include "battle_scene.hpp"

#include "../camera/camera.hpp"
#include "../entities/entity_factory.hpp"
#include "../systems/damage_system.hpp"
#include "../systems/debug_render_system.hpp"
#include "../systems/enemy_dispose_system.hpp"
#include "../systems/movement_system.hpp"
#include "../systems/projectile_system.hpp"
#include "../systems/render_system.hpp"
#include "../systems/shooting_system.hpp"
#include "../systems/sound_system.hpp"
#include "../systems/targeting_system.hpp"
#include "assets/level_interface.hpp"
#include "components/position_component.hpp"
#include "components/tower_component.hpp"
#include "components/transform_component.hpp"
#include "loguru/loguru.hpp"
#include "renderer/renderer_interface.hpp"

namespace game
{

Battle_scene::Battle_scene(entt::registry& registry,
                           Camera& camera,
                           renderer::Renderer_interface& renderer,
                           sound::Sound_player_interface& sound_player,
                           input::Input_handler_interface& input_handler)
    : Scene(registry, camera, renderer, sound_player, input_handler)
{
    setup_input_handler();
    entity::factory::create_debug_entity(registry, 608.0f, 362.0f);
    entity::factory::create_debug_entity(registry, 608.0f, 608.f);
}

void Battle_scene::setup_input_handler()
{
    m_input_handler.handle_mouse_left_click(
        [&camera = m_camera, &registry = m_registry](int x, int y)
        {
            // TODO check mouse click in order
            // 1. HUD
            // .. TBD, there's  no hud yet
            // 2. towers
            const auto viewport = camera.get_viewport_size();
            // TODO this is now quite ugly: RenderTexture seems to render 0,0 to bottomleft (due to FBO?)
            // -> Need to find a proper solution, but for now our 0,0 is at bottomleft.
            const math::Int_vector mouse_pos = {x, static_cast<int>(viewport.y) - y};
            auto tower_view =
                registry.view<const game::comp::Tower, game::comp::Position, const game::comp::Transform>();
            // use forward iterators and get only the components of interest
            for (auto entity : tower_view)
            {
                auto& pos = tower_view.get<const game::comp::Position>(entity);
                auto& transform = tower_view.get<const game::comp::Transform>(entity);

                const float width = static_cast<float>(transform.width) * transform.scale;
                const float height = static_cast<float>(transform.height) * transform.scale;
                const math::Float_rect tower_rect = {pos.x - width / 2, pos.y - height / 2, width, height};

                const auto hit = tower_rect.contains(
                    math::Float_vector{static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y)});
                if (hit)
                {
                    LOG_F(INFO, "mouse click HIT: %d, %d", mouse_pos.x, mouse_pos.y);
                }
            }
        });
    m_input_handler.enable();
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
    m_input_handler.disable();
    m_enemy_spawner.set_level(std::weak_ptr<Level>());
}

void Battle_scene::update(const float delta_time)
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
    sys::Targeting_system::release_targets(m_registry);
    sys::Targeting_system::acquire_targets(m_registry);
    sys::Shooting_system::shoot_enemies(m_registry, delta_time);
    sys::Damage_system::deal_damage(m_registry);
    sys::Projectile_system::destroy_projectiles(m_registry);
    sys::Enemy_dispose_system::dispose_enemies_by_health(m_registry);
    execute_sound_systems(delta_time);
    execute_renderers(delta_time);
}

void Battle_scene::execute_sound_systems(const float delta_time)
{
    sys::Sound_system::play_hit_sounds(m_sound_player, m_registry);
}

void Battle_scene::execute_renderers(const float delta_time)
{
#ifdef DEBUG
    sys::debug::Render_system::render_grid(m_renderer.get_shape_renderer());
    sys::debug::Render_system::render_shoot_radiuses(m_renderer.get_shape_renderer(), m_registry);
#endif
    sys::Render_system::render_level(m_renderer.get_level_renderer());
    sys::Render_system::render_sprites(m_registry, m_renderer.get_sprite_renderer());
    sys::Render_system::render_sprite_animations(m_registry, m_renderer.get_sprite_renderer(), delta_time);
    sys::Render_system::render_hitpoints(m_registry, m_renderer.get_shape_renderer());

    // TODO hook to events
    const bool display_hud = false;
    if (display_hud)
    {
        sys::Render_system::render_hud(m_renderer.get_hud_renderer());
    }
}

}  // namespace game