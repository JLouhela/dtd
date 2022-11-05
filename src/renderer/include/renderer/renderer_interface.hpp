#pragma once

#include <memory>

#include "sprite_renderer_interface.hpp"

#ifdef DEBUG
#include "debug_renderer_interface.hpp"
#endif

namespace sf
{
class Window;
class Event;
}  // namespace sf

namespace renderer
{

#ifdef DEBUG
class Debug_renderer_interface;
#endif

class Renderer_interface
{
public:
    virtual ~Renderer_interface() = default;
    virtual void render() = 0;
    virtual void close_window() = 0;
    virtual sf::Window& get_window() = 0;

    virtual Sprite_renderer_interface& get_sprite_renderer() = 0;

#ifdef DEBUG
    virtual Debug_renderer_interface& get_debug_renderer() = 0;
#endif
};

std::unique_ptr<Renderer_interface> make_renderer();

}  // namespace renderer