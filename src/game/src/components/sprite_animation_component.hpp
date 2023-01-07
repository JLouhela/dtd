#pragma once

#include <cstdint>

#include "renderer/sprite_id.hpp"

namespace game::comp
{

struct Sprite_animation
{
    // TODO add frames & frametime
    renderer::Sprite_id sprite{renderer::Sprite_id::Rectangle_black};
    float duration{1.0f};
};

}  // namespace game::comp