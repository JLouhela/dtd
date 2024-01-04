#pragma once

#include <memory>

#include "hud_renderer_interface.hpp"
#include "level_renderer_interface.hpp"
#include "shape_renderer_interface.hpp"
#include "sprite_renderer_interface.hpp"

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

class Renderer_interface
{
public:
    virtual ~Renderer_interface() = default;
    virtual void render() = 0;
    virtual void clear() = 0;
    virtual void close_window() = 0;
    [[nodiscard]] virtual sf::Window& get_window() = 0;
    [[nodiscard]] virtual math::UInt_vector get_window_size() = 0;

    [[nodiscard]] virtual Sprite_renderer_interface& get_sprite_renderer() = 0;
    [[nodiscard]] virtual Hud_renderer_interface& get_hud_renderer() = 0;
    [[nodiscard]] virtual Level_renderer_interface& get_level_renderer() = 0;
    [[nodiscard]] virtual Shape_renderer_interface& get_shape_renderer() = 0;
};

std::unique_ptr<Renderer_interface> make_renderer(const assets::Assets_interface& assets);

}  // namespace renderer