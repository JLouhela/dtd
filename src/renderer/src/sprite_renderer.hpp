#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "renderer/sprite_renderer_interface.hpp"
#include "sprite_cache.hpp"
#include "subrenderer.hpp"

namespace assets
{
class Assets_interface;
}

namespace renderer
{

class Sprite_renderer : public Sprite_renderer_interface, public Subrenderer
{
public:
    Sprite_renderer(std::shared_ptr<Sprite_cache> sprite_cache);
    void render_sprite(const Sprite_id& sprite_id, const Screen_coord& screen_coord) final;
};

}  // namespace renderer
