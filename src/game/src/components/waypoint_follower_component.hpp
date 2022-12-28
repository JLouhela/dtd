#pragma once

#include <cstdint>

namespace game
{
namespace comp
{

struct Waypoint_follower
{
    std::int8_t spawn_index{-1};
    std::int8_t waypoint_index{-1};
};

}  // namespace comp
}  // namespace game