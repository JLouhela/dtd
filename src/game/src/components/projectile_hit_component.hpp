#pragma once

#include "../entities/projectile_type.hpp"

namespace game::comp
{

struct Projectile_hit
{
    game::entity::Projectile_type projectile_type;
};

}  // namespace game::comp