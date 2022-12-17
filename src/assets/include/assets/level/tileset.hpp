#pragma once

#include <cstdint>
#include <string>

#include "../asset_id.hpp"
#include "SFML/Graphics.hpp"

namespace assets
{
namespace level
{

struct Tile
{
    // TODO vertices based on padding / margin
    Tile(const sf::Vector2f& top_left, const sf::Vector2f bottom_right)
    {
    }
    sf::VertexArray vertices;
};

class Tileset
{
public:
    const Asset_id& get_texture_id()
    {
        // TODO when filling this: add filename table to assets
        return m_texture_id;
    }

    std::uint32_t get_margin()
    {
        return m_margin;
    }

    std::uint32_t get_padding()
    {
        return m_padding;
    }

    std::uint32_t get_tile_size()
    {
        return m_tile_size;
    }

    std::uint32_t has_tile(std::uint32_t id);

private:
    Asset_id m_texture_id;
    std::uint32_t m_first_gid{0};
    std::uint32_t m_last_gid{0};
    std::uint32_t m_margin{0};
    std::uint32_t m_padding{0};
    std::uint32_t m_tile_size{0};
};

}  // namespace level

}  // namespace assets