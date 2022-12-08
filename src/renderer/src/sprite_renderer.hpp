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

private:
    Sprite_cache m_sprite_cache;
};

}  // namespace renderer
