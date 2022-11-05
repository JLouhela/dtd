#pragma once

#include "renderer/screen_coord.hpp"

namespace renderer
{

class Debug_renderer_interface
{
public:
    virtual ~Debug_renderer_interface() = default;
    virtual void draw_line(const Screen_coord& start, const Screen_coord& end) = 0;
    virtual void draw_grid(std::uint8_t grid_size) = 0;

    // TODO own color abstraction to not expose sfml-graphics outside
    //  virtual void draw_line(const Screen_coord& start, const Screen_coord& end, const sf::Color& color) = 0;
};

}  // namespace renderer