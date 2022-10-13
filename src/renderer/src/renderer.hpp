#pragma once

#include <SFML/Graphics.hpp>

#include "renderer/renderer_interface.hpp"

#ifdef DEBUG
#include "debug_renderer.hpp"
#endif

namespace renderer
{

class Renderer : public Renderer_interface
{
public:
    Renderer();
    ~Renderer() final = default;
    void render() final;
    void close_window() final;
    sf::Window& get_window() final;

#ifdef DEBUG
    Debug_renderer_interface& get_debug_renderer() final
    {
        return m_debug_renderer;
    }
#endif

private:
    sf::RenderWindow m_window;
#ifdef DEBUG
    Debug_renderer m_debug_renderer;
#endif
};

}  // namespace renderer
