#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>

#include "renderer/shape_renderer_interface.hpp"
#include "subrenderer.hpp"

namespace renderer
{

class Shape_renderer : public Shape_renderer_interface, public Subrenderer
{
public:
    Shape_renderer();
    ~Shape_renderer() = default;
    void draw_line(const Screen_coord& center, const Screen_coord& end) final;
    void draw_circle(const Screen_coord& start, float radius) final;
    void draw_grid(std::uint8_t grid_size) final;

private:
    void draw_line(const Screen_coord& start, const Screen_coord& end, const sf::Color& color);
};

}  // namespace renderer
