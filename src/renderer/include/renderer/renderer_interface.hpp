#pragma once

#include <memory>

namespace sf
{
class RenderWindow;
}

namespace renderer
{

class Renderer_interface
{
public:
    virtual ~Renderer_interface() = default;
    virtual sf::RenderWindow& get_window() = 0;
};

std::unique_ptr<Renderer_interface> make_renderer();

}  // namespace renderer