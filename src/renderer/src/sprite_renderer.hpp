#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>

#include "renderer/sprite_renderer_interface.hpp"

namespace renderer
{

class Sprite_renderer : public Sprite_renderer_interface
{
public:
    void render_sprite(const Sprite_id& sprite_id, const Screen_coord& screen_coord) final;

private:
};

}  // namespace renderer
