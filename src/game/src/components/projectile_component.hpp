#pragma once

#include <cstdint>

#include "math/vector.hpp"

namespace game::comp
{

struct Projectile
{
    Projectile(float damage, math::Float_vector target_pos)
        : damage{damage}, target_pos{std::move(target_pos)}, prev_pos{-9999999.f, -9999999.f}
    {
    }
    float damage{0.0f};
    math::Float_vector target_pos{0.0f, 0.0f};
    math::Float_vector prev_pos{0.0f, 0.0f};
};

}  // namespace game::comp