#pragma once

#include <string>
#include <unordered_map>

namespace renderer
{
enum class Sprite_id
{
    Rectangle_black,
    Rectangle_green,
    Rectangle_red,
    Basic_enemy,
    Basic_tower,
};

static const std::unordered_map<std::string, Sprite_id> ENEMY_SPRITES{{"basic", Sprite_id::Basic_enemy}};

Sprite_id get_enemy_sprite(const std::string& enemy_type);

}  // namespace renderer