#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "math/vector.hpp"

namespace assets
{

namespace level
{

struct Enemy
{
    Enemy(std::string type, std::uint32_t count, std::uint32_t spawn_time)
        : type{type}, count{count}, spawn_time{spawn_time}
    {
    }
    std::string type{"unknown"};
    std::uint32_t count{0};
    std::uint32_t spawn_time{0};
};

struct Enemy_wave
{
    std::vector<Enemy> enemies;
};

struct Waypoint
{
    Waypoint(float x, float y) : point{x, y}
    {
    }
    math::Float_vector point{0, 0};
};

struct Waypoints
{
    std::vector<Waypoint> waypoints;
};

class Level_interface
{
public:
    virtual const std::string& get_id() const = 0;
    virtual const std::vector<Enemy_wave>& get_waves() const = 0;
    virtual const std::vector<Waypoints>& get_waypoints() const = 0;
};

}  // namespace level
}  // namespace assets