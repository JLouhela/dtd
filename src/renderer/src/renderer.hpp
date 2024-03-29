#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "hud_renderer.hpp"
#include "level_renderer.hpp"
#include "renderer/renderer_interface.hpp"
#include "shape_renderer.hpp"
#include "sprite_cache.hpp"
#include "sprite_renderer.hpp"

namespace renderer
{

class Renderer : public Renderer_interface
{
public:
    Renderer(const assets::Assets_interface& assets);
    ~Renderer() final = default;
    void render() final;
    void clear() final;
    void close_window() final;
    sf::Window& get_window() final;
    math::UInt_vector get_window_size() final;

    Sprite_renderer_interface& get_sprite_renderer() final
    {
        return m_sprite_renderer;
    }

    Hud_renderer_interface& get_hud_renderer() final
    {
        return m_hud_renderer;
    }

    Level_renderer_interface& get_level_renderer() final
    {
        return m_level_renderer;
    }

    Shape_renderer_interface& get_shape_renderer() final
    {
        return m_shape_renderer;
    }

private:
    sf::RenderWindow m_window;
    const assets::Assets_interface& m_assets;
    std::shared_ptr<Sprite_cache> m_sprite_cache;
    Sprite_renderer m_sprite_renderer;
    Hud_renderer m_hud_renderer;
    Level_renderer m_level_renderer;
    Shape_renderer m_shape_renderer;
};

}  // namespace renderer
