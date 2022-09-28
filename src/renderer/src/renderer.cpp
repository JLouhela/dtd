#include "renderer.hpp"

namespace renderer
{

Renderer::Renderer() : m_window{sf::VideoMode{sf::Vector2{200u, 200u}, 32u}, "SFML works!"}
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
}

void Renderer::render()
{
    m_window.clear();
    // TODO render tex to screen
    m_window.display();
}

bool Renderer::has_window()
{
    return m_window.isOpen();
}

bool Renderer::close_window()
{
    m_window.close();
}

bool Renderer::get_window_event(sf::Event& event)
{
    return m_window.pollEvent(event);
}

std::unique_ptr<Renderer_interface> make_renderer()
{
    return std::make_unique<Renderer>();
}
}  // namespace renderer