#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "hud_renderer.hpp"
#include "level_renderer.hpp"
#include "renderer/level_renderer_interface.hpp"
#include "renderer/renderer_interface.hpp"
#include "sprite_cache.hpp"
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
    void clear() final;
    void close_window() final;
    sf::Window& get_window() final;

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

#ifdef DEBUG
    Debug_renderer_interface& get_debug_renderer() final
    {
        return m_debug_renderer;
    }
#endif

private:
    sf::RenderWindow m_window;
    const assets::Assets_interface& m_assets;
    std::shared_ptr<Sprite_cache> m_sprite_cache;
    Sprite_renderer m_sprite_renderer;
    Hud_renderer m_hud_renderer;
    Level_renderer m_level_renderer;
#ifdef DEBUG
    Debug_renderer m_debug_renderer;
#endif
};

}  // namespace renderer
