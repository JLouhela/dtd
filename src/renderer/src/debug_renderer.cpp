#include "debug_renderer.hpp"

#include "loguru/loguru.hpp"
#include "window_size.hpp"

namespace renderer
{

Debug_renderer::Debug_renderer() : Subrenderer(nullptr)
{
}

void Debug_renderer::draw_line(const Screen_coord& start, const Screen_coord& end, const sf::Color& color)
{
    sf::VertexArray line(sf::Lines, 2);

    line[0].position = sf::Vector2f(static_cast<float>(start.x), static_cast<float>(start.y));
    line[1].position = sf::Vector2f(static_cast<float>(end.x), static_cast<float>(end.y));

    line[0].color = color;
    line[1].color = color;
    draw(line);
}

void Debug_renderer::draw_line(const Screen_coord& start, const Screen_coord& end)
{
    draw_line(start, end, sf::Color::Black);
}

void Debug_renderer::draw_grid(const std::uint8_t grid_size)
{
    const auto& screen_size = constants::WINDOW_SIZE;
    const auto row_count = screen_size.y / grid_size;
    const auto col_count = screen_size.x / grid_size;

    for (int y = 0; y < static_cast<int>(row_count); ++y)
    {
        draw_line({0, y * grid_size}, {static_cast<std::int32_t>(screen_size.x), y * grid_size});
    }
    for (int x = 0; x < static_cast<int>(col_count); ++x)
    {
        draw_line({x * grid_size, 0}, {x * grid_size, static_cast<std::int32_t>(screen_size.y)});
    }
}

}  // namespace renderer
