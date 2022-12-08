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
    : m_window{sf::VideoMode{constants::WINDOW_SIZE, 32u}, "Dtd!"}, m_assets{assets}, m_sprite_renderer{assets}
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
}

void Renderer::render()
{
    m_window.clear(bg_color);
#ifdef DEBUG
    sf::Sprite debug_tex(m_debug_renderer.get_render_texture().getTexture());
    m_window.draw(debug_tex);
    // TODO separate render & clear in renderer interface -> clear there before game logic
    m_debug_renderer.clear();

#endif
    m_window.display();
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