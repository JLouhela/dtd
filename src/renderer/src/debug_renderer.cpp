#include "debug_renderer.hpp"

#include "window_size.hpp"

namespace renderer
{

Debug_renderer::Debug_renderer()
{
    m_render_texture.create(constants::WINDOW_SIZE);
}

void Debug_renderer::draw_line(const Screen_coord& start, const Screen_coord& end, const sf::Color& color)
{
    sf::VertexArray line(sf::Lines, 2);

    line[0].position = sf::Vector2f(static_cast<float>(start.x), static_cast<float>(start.y));
    line[1].position = sf::Vector2f(static_cast<float>(end.x), static_cast<float>(end.y));

    line[0].color = color;
    line[1].color = color;
    m_render_texture.draw(line);
}

void Debug_renderer::draw_line(const Screen_coord& start, const Screen_coord& end)
{
    draw_line(start, end, sf::Color::Black);
}

void Debug_renderer::clear()
{
    m_render_texture.clear(sf::Color::Transparent);
}

void Debug_renderer::render()
{
    m_render_texture.display();
}

}  // namespace renderer
