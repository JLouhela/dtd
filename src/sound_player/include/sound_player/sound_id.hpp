#pragma once

#include <string>
#include <unordered_map>

#include "types/projectile_type.hpp"

namespace sound
{
enum class Sound_id
{
    Silent,
    Basic_projectile_hit_1,
};

static const std::unordered_map<types::Projectile_type, Sound_id> HIT_SOUNDS{
    {types::Projectile_type::basic, Sound_id::Basic_projectile_hit_1}};

Sound_id get_hit_sound(const types::Projectile_type& projectile_type);

}  // namespace sound