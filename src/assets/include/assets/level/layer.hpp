#pragma once

#include <vector>

namespace assets
{
namespace level
{
struct Tile
{
    std::uint32_t id{0};
};
struct Layer
{
    std::vector<Tile> tiles;
};

}  // namespace level
}  // namespace assets