#pragma once

#include "renderer/screen_coord.hpp"
#include "sprite_id.hpp"

namespace renderer
{

class Sprite_renderer_interface
{
public:
    virtual ~Sprite_renderer_interface() = default;

    virtual void render_sprite(const Sprite_id& sprite_id, const Screen_coord& screen_coord) = 0;
};

}  // namespace renderer