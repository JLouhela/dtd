#pragma once

#include <memory>

namespace sf
{
class RenderWindow;
class Event;
}  // namespace sf

namespace renderer
{

class Renderer_interface
{
public:
    virtual ~Renderer_interface() = default;
    virtual void render() = 0;
    virtual bool has_window() = 0;
    virtual bool close_window() = 0;
    virtual bool get_window_event(sf::Event& event);
};

std::unique_ptr<Renderer_interface> make_renderer();

}  // namespace renderer