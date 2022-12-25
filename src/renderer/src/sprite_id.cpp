#pragma once

#include "renderer/sprite_id.hpp"

#include "loguru/loguru.hpp"

namespace renderer
{

Sprite_id get_enemy_sprite(const std::string& enemy_type)
{
    const auto it = ENEMY_SPRITES.find(enemy_type);
    if (it != ENEMY_SPRITES.end())
    {
        return it->second;
    }
    LOG_F(WARNING, "Sprite with id %s does not exist / mapping missing!", enemy_type.c_str());
    return Sprite_id::Rectangle_black;
}

}  // namespace renderer