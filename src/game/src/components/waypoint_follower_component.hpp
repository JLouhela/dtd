#pragma once

#include "math/vector.hpp"

namespace game
{
namespace comp
{

struct Waypoint_follower
{
    // Will likely need some adjustments, e.g.
    math::Float_vector previous_waypoint{0.0f, 0.0f};
};

}  // namespace comp
}  // namespace game