#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "math/vector.hpp"
#include "types/asset_id.hpp"

namespace assets
{
namespace level
{

struct Tileset
{
    struct Tile
    {
        // TODO vertices based on padding / margin
        Tile(std::uint32_t id, std::vector<math::Float_vector> vertices) : id{id}, vertices{std::move(vertices)}
        {
        }
        std::uint32_t id{0};
        std::vector<math::Float_vector> vertices;
    };

    types::Asset_id texture_id{"unknown"};
    std::uint32_t first_gid{0};
    std::uint32_t last_gid{0};
    math::Int_vector tile_size{0, 0};
    std::vector<Tile> tiles;
};

}  // namespace level

}  // namespace assets