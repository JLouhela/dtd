#pragma once

#include <cstdint>

#include "math/rect.hpp"
#include "renderer/shape_renderer_interface.hpp"
#include "subrenderer.hpp"

namespace sf
{
class Color;
}

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
    void draw_rect(const math::Float_rect& rect, const Color& outline_color) final;
    void draw_fill_rect(const math::Float_rect& rect, const Color& outline_color, const Color& fill_color) final;

private:
    void draw_line(const Screen_coord& start, const Screen_coord& end, const sf::Color& color);
};

}  // namespace renderer
