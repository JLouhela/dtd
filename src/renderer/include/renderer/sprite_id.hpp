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
    Basic_projectile
};

static const std::unordered_map<std::string, Sprite_id> ENEMY_SPRITES{{"basic", Sprite_id::Basic_enemy}};
static const std::unordered_map<std::string, Sprite_id> PROJECTILE_SPRITES{{"basic", Sprite_id::Basic_projectile}};

Sprite_id get_enemy_sprite(const std::string& enemy_type);
Sprite_id get_projectile_sprite(const std::string& projectile_type);

}  // namespace renderer