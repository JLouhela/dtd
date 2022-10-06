#include "renderer.hpp"

namespace renderer
{

Renderer::Renderer() : m_window{sf::VideoMode{sf::Vector2{500u, 500u}, 32u}, "Dtd!"}
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

void Renderer::close_window()
{
    m_window.close();
}

sf::Window& Renderer::get_window()
{
    return m_window;
}

std::unique_ptr<Renderer_interface> make_renderer()
{
    return std::make_unique<Renderer>();
}
}  // namespace renderer