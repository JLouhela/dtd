#pragma once

#include <vector>

namespace assets
{
namespace level
{
struct Layer
{
    struct Tile
    {
        Tile(std::uint32_t id) : id{id}
        {
        }
        std::uint32_t id{0};
    };
    std::vector<Tile> tiles;
    std::uint32_t width{0};
};

}  // namespace level
}  // namespace assets