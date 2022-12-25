#pragma once

#include <cstdint>

#include "renderer/sprite_id.hpp"

namespace game
{
namespace comp
{

struct Sprite
{
    renderer::Sprite_id sprite{renderer::Sprite_id::Rectangle_black};
};

}  // namespace comp
}  // namespace game