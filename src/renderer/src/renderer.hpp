#pragma once

#include <SFML/Graphics.hpp>

#include "renderer/renderer_interface.hpp"
#include "sprite_renderer.hpp"

#ifdef DEBUG
#include "debug_renderer.hpp"
#endif

namespace renderer
{

class Renderer : public Renderer_interface
{
public:
    Renderer(const assets::Assets_interface& assets);
    ~Renderer() final = default;
    void render() final;
    void close_window() final;
    sf::Window& get_window() final;

    Sprite_renderer_interface& get_sprite_renderer() final
    {
        return m_sprite_renderer;
    }

#ifdef DEBUG
    Debug_renderer_interface& get_debug_renderer() final
    {
        return m_debug_renderer;
    }
#endif

private:
    sf::RenderWindow m_window;
    const assets::Assets_interface& m_assets;
    Sprite_renderer m_sprite_renderer;
#ifdef DEBUG
    Debug_renderer m_debug_renderer;
#endif
};

}  // namespace renderer
