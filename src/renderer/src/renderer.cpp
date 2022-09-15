#include "renderer.hpp"

namespace renderer
{

Renderer::Renderer() : m_window{sf::VideoMode{sf::Vector2{200u, 200u}, 32u}, "SFML works!"}
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
}

sf::RenderWindow& Renderer::get_window()
{
    return m_window;
}

std::unique_ptr<Renderer_interface> make_renderer()
{
    return std::make_unique<Renderer>();
}
}