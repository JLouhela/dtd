#pragma once

#include <cstdint>
#include <vector>

#include "renderer/sprite_id.hpp"

namespace game::comp
{
static constexpr float DEFAULT_FRAME_DURATION = 0.1f;

struct Sprite_animation
{
    std::vector<renderer::Sprite_id> frames{renderer::Sprite_id::Rectangle_black};
    float duration{1.0f};
    float frame_duration{DEFAULT_FRAME_DURATION};
    std::uint8_t cur_frame{0};
};

}  // namespace game::comp