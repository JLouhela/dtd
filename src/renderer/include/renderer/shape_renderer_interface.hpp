#pragma once

#include "math/rect.hpp"
#include "renderer/screen_coord.hpp"

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

class Shape_renderer_interface
{
public:
    virtual ~Shape_renderer_interface() = default;
    virtual void draw_line(const Screen_coord& start, const Screen_coord& end) = 0;
    virtual void draw_circle(const Screen_coord& start, float radius) = 0;
    virtual void draw_grid(std::uint8_t grid_size) = 0;
    virtual void draw_rect(const math::Float_rect& rect, const Color& outline_color) = 0;
    virtual void draw_fill_rect(const math::Float_rect& rect, const Color& outline_color, const Color& fill_color) = 0;

    //  virtual void draw_line(const Screen_coord& start, const Screen_coord& end, const sf::Color& color) = 0;
};

}  // namespace renderer