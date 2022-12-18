#pragma once

#include <cstdint>
#include <string>
#include <vector>

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

class Level_interface
{
public:
    virtual const std::string& get_id() const = 0;
    virtual const std::vector<Enemy_wave>& get_waves() const = 0;
    // TODO mitä tarvitaan logiikkaaN?
    // waypointit
    // spawnihommat (joku tiled metadata -> Json file?)
};

}  // namespace level
}  // namespace assets