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

// Decouple SFML, don't leak
struct Color
{
    std::uint8_t r{0};
    std::uint8_t g{0};
    std::uint8_t b{0};
    std::uint8_t a{255};
};

class Shape_renderer : public Shape_renderer_interface, public Subrenderer
{
public:
    Shape_renderer();
    ~Shape_renderer() = default;
    void draw_line(const Screen_coord& center, const Screen_coord& end) final;
    void draw_circle(const Screen_coord& start, float radius) final;
    void draw_grid(std::uint8_t grid_size) final;
    void draw_rect(const math::Float_rect& rect, const Color& outline_color);
    void draw_fill_rect(const math::Float_rect& rect, const Color& outline_color, const Color& fill_color);

private:
    void draw_line(const Screen_coord& start, const Screen_coord& end, const sf::Color& color);
};

}  // namespace renderer
