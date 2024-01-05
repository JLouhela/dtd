#include "shape_renderer.hpp"

#include <SFML/Graphics.hpp>

#include "loguru/loguru.hpp"
#include "window_size.hpp"

namespace
{
sf::RectangleShape get_rect(const math::Float_rect& rect, const renderer::Color& outline_color)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(rect.width, rect.height));
    rectangle.setOutlineColor({outline_color.r, outline_color.g, outline_color.b, outline_color.a});
    rectangle.setOutlineThickness(2);
    rectangle.setPosition({rect.top_left.x, rect.top_left.y});
    return rectangle;
}
}  // namespace

namespace renderer
{
Shape_renderer::Shape_renderer() : Subrenderer(nullptr)
{
}

void Shape_renderer::draw_line(const Screen_coord& start, const Screen_coord& end, const sf::Color& color)
{
    sf::VertexArray line(sf::PrimitiveType::Lines, 2);

    line[0].position = sf::Vector2f(static_cast<float>(start.x), static_cast<float>(start.y));
    line[1].position = sf::Vector2f(static_cast<float>(end.x), static_cast<float>(end.y));

    line[0].color = color;
    line[1].color = color;
    draw(line);
}

void Shape_renderer::draw_line(const Screen_coord& start, const Screen_coord& end)
{
    draw_line(start, end, sf::Color::Black);
}

void Shape_renderer::draw_circle(const Screen_coord& center, float radius)
{
    sf::CircleShape circle;
    circle.setRadius(radius);
    circle.setOutlineColor(sf::Color::Red);
    circle.setFillColor({200, 0, 0, 128});
    circle.setOrigin({radius, radius});
    circle.setOutlineThickness(1);
    circle.setPosition({static_cast<float>(center.x), static_cast<float>(center.y)});
    draw(circle);
}

void Shape_renderer::draw_grid(const std::uint8_t grid_size)
{
    const auto& screen_size = constants::WINDOW_SIZE;
    const auto row_count = screen_size.y / grid_size;
    const auto col_count = screen_size.x / grid_size;

    for (int y = 0; y <= static_cast<int>(row_count); ++y)
    {
        draw_line({0, y * grid_size}, {static_cast<std::int32_t>(screen_size.x), y * grid_size});
    }
    for (int x = 0; x <= static_cast<int>(col_count); ++x)
    {
        draw_line({x * grid_size, 0}, {x * grid_size, static_cast<std::int32_t>(screen_size.y)});
    }
}

void Shape_renderer::draw_rect(const math::Float_rect& rect, const Color& outline_color)
{
    const auto rectangle = get_rect(rect, outline_color);
    draw(rectangle);
}

void Shape_renderer::draw_fill_rect(const math::Float_rect& rect, const Color& outline_color, const Color& fill_color)
{
    auto rectangle = get_rect(rect, outline_color);
    rectangle.setFillColor({fill_color.r, fill_color.g, fill_color.b, fill_color.a});
    draw(rectangle);
}

}  // namespace renderer
