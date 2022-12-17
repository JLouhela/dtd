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
};

}  // namespace level
}  // namespace assets