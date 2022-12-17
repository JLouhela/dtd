#include "renderer.hpp"

#include "window_size.hpp"

namespace
{
constexpr sf::Color bg_color{145, 178, 199};
}  // namespace

namespace renderer
{

// TODO configure
Renderer::Renderer(const assets::Assets_interface& assets)
    : m_window{sf::VideoMode{constants::WINDOW_SIZE, 32u}, "Dtd!"},
      m_assets{assets},
      m_sprite_cache{std::make_shared<Sprite_cache>(assets)},
      m_sprite_renderer{m_sprite_cache},
      m_hud_renderer{m_sprite_cache},
      m_level_renderer{assets}
{
}

void Renderer::render()
{
    m_window.clear(bg_color);
#ifdef DEBUG
    sf::Sprite debug(m_debug_renderer.get_render_texture().getTexture());
    m_window.draw(debug);
#endif

    sf::Sprite level(m_level_renderer.get_render_texture().getTexture());
    m_window.draw(level);

    sf::Sprite sprites(m_sprite_renderer.get_render_texture().getTexture());
    m_window.draw(sprites);

    sf::Sprite hud(m_hud_renderer.get_render_texture().getTexture());
    m_window.draw(hud);

    m_window.display();
}

void Renderer::clear()
{
#ifdef DEBUG
    m_debug_renderer.clear();
#endif
    m_level_renderer.clear();
    m_sprite_renderer.clear();
    m_hud_renderer.clear();
}

void Renderer::close_window()
{
    m_window.close();
}

sf::Window& Renderer::get_window()
{
    return m_window;
}

std::unique_ptr<Renderer_interface> make_renderer(const assets::Assets_interface& assets)
{
    return std::make_unique<Renderer>(assets);
}
}  // namespace renderer