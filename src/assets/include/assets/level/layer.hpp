#pragma once

#include <vector>

namespace assets
{
namespace level
{
struct Tile
{
    Tile(std::uint32_t id) : id{id}
    {
    }
    std::uint32_t id{0};
};
struct Layer
{
    std::vector<Tile> tiles;
};

}  // namespace level
}  // namespace assets