#pragma once

#include <memory>

namespace sf
{
class Window;
class Event;
}  // namespace sf

namespace renderer
{

class Renderer_interface
{
public:
    virtual ~Renderer_interface() = default;
    virtual void render() = 0;
    virtual void close_window() = 0;
    virtual sf::Window& get_window() = 0;
};

std::unique_ptr<Renderer_interface> make_renderer();

}  // namespace renderer