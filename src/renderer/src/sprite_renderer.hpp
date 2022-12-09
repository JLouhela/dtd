#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>

#include "renderer/sprite_renderer_interface.hpp"
#include "sprite_cache.hpp"

namespace assets
{
class Assets_interface;
}

namespace renderer
{

class Sprite_renderer : public Sprite_renderer_interface
{
public:
    Sprite_renderer(const assets::Assets_interface& assets);
    void render_sprite(const Sprite_id& sprite_id, const Screen_coord& screen_coord) final;

    sf::RenderTexture& get_render_texture()
    {
        return m_render_texture;
    }

    void clear();
    void render();

private:
    sf::RenderStates m_renderStates{sf::RenderStates::Default};
    Sprite_cache m_sprite_cache;
    sf::RenderTexture m_render_texture;
};

}  // namespace renderer
