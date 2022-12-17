#pragma once

#include <memory>

#include "hud_renderer_interface.hpp"
#include "level_renderer_interface.hpp"
#include "sprite_renderer_interface.hpp"

#ifdef DEBUG
#include "debug_renderer_interface.hpp"
#endif

namespace sf
{
class Window;
class Event;
}  // namespace sf

namespace assets
{
class Assets_interface;
}

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
    virtual void clear() = 0;
    virtual void close_window() = 0;
    virtual sf::Window& get_window() = 0;

    virtual Sprite_renderer_interface& get_sprite_renderer() = 0;
    virtual Hud_renderer_interface& get_hud_renderer() = 0;
    virtual Level_renderer_interface& get_level_renderer() = 0;

#ifdef DEBUG
    virtual Debug_renderer_interface& get_debug_renderer() = 0;
#endif
};

std::unique_ptr<Renderer_interface> make_renderer(const assets::Assets_interface& assets);

}  // namespace renderer