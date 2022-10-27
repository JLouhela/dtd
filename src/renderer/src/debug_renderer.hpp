#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>

#include "renderer/debug_renderer_interface.hpp"

namespace renderer
{

class Debug_renderer : public Debug_renderer_interface
{
public:
    Debug_renderer();
    ~Debug_renderer() = default;
    void draw_line(const Screen_coord& start, const Screen_coord& end) final;
    void draw_grid(std::uint8_t grid_size) final;

    void clear();
    void render();
    sf::RenderTexture& get_render_texture()
    {
        return m_render_texture;
    }

private:
    void draw_line(const Screen_coord& start, const Screen_coord& end, const sf::Color& color);
    sf::RenderTexture m_render_texture;
};

}  // namespace renderer
