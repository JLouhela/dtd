#include "system_manager.hpp"

#include "render_system.hpp"
#include "renderer/renderer_interface.hpp"
#ifdef DEBUG
#include "debug_render_system.hpp"
#endif
namespace game
{

System_manager::System_manager(entt::registry& registry, renderer::Renderer_interface& renderer)
    : m_registry{registry}, m_renderer{renderer}
{
}

void System_manager::execute()
{
    execute_renderers();
}

void System_manager::execute_renderers()
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