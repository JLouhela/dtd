#pragma once

#include <cstdint>

#include "math/vector.hpp"
#include "types/entity_id.hpp"

namespace game::comp
{

struct Damage
{
    Damage(float damage, float radius) : damage{damage}, radius{radius}
    {
    }
    // TODO consider integers for the sake of floating point math
    float damage{0.0f};
    float radius{0.0f};
};

}  // namespace game::comp