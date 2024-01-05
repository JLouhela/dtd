#include "level_renderer.hpp"

#include <algorithm>
#include <cstdint>

#include "assets/assets_interface.hpp"
#include "assets/level/tileset.hpp"
#include "assets/render_level_interface.hpp"
#include "loguru/loguru.hpp"
#include "window_size.hpp"

namespace
{
const assets::level::Tileset* find_tile_set(const std::vector<assets::level::Tileset>& tilesets,
                                            const std::vector<assets::level::Layer::Tile>& tiles)
{
    std::uint32_t id = 0;
    const auto id_it = std::find_if(std::cbegin(tiles), std::cend(tiles),
                                    [](const assets::level::Layer::Tile& tile) { return tile.id != 0; });
    if (id_it == std::end(tiles))
    {
        return nullptr;
    }
    id = id_it->id;
    auto it = std::find_if(std::begin(tilesets), std::end(tilesets),
                           [id](const assets::level::Tileset& tileset)
                           { return tileset.first_gid <= id && tileset.last_gid >= id; });
    return it == std::end(tilesets) ? nullptr : &(*it);
}

void render_layer(const assets::level::Layer& layer, const assets::level::Tileset& tileset, sf::VertexArray& vertices)
{
    // TODO only render camera range
    std::uint32_t x = 0;
    std::uint32_t y = 0;
    const auto tile_size = tileset.tile_size;
    for (const auto& tile : layer.tiles)
    {
        if (tile.id == 0)
        {
            continue;
        }
        const auto render_tile_it =
            std::lower_bound(std::begin(tileset.tiles), std::end(tileset.tiles), tile.id,
                             [](const assets::level::Tileset::Tile& tile, std::uint32_t id) { return tile.id < id; });
        if (render_tile_it == std::end(tileset.tiles) || render_tile_it->id != tile.id)
        {
            LOG_F(ERROR, "Tileset does not contain tile %d", tile.id);
            continue;
        }

        sf::Vertex* triangles = &vertices[(x + y * layer.width) * 6];
        triangles[0].position = sf::Vector2f(static_cast<float>(x * tile_size.x), static_cast<float>(y * tile_size.y));
        triangles[1].position =
            sf::Vector2f(static_cast<float>((x + 1) * tile_size.x), static_cast<float>((y * tile_size.y)));
        triangles[2].position =
            sf::Vector2f(static_cast<float>((x + 1) * tile_size.x), static_cast<float>((y + 1) * tile_size.y));
        triangles[3].position =
            sf::Vector2f(static_cast<float>((x + 1) * tile_size.x), static_cast<float>((y + 1) * tile_size.y));
        triangles[4].position =
            sf::Vector2f(static_cast<float>(x * tile_size.x), static_cast<float>((y + 1) * tile_size.y));
        triangles[5].position = sf::Vector2f(static_cast<float>(x * tile_size.x), static_cast<float>(y * tile_size.y));

        for (int i = 0; i < 6; ++i)
        {
            const auto& tex_coord = render_tile_it->vertices[i];
            triangles[i].texCoords = {tex_coord.x, tex_coord.y};
        }

        ++x;
        if (x >= layer.width)
        {
            x = 0;
            ++y;
        }
    }
}

}  // namespace

namespace renderer
{

Level_renderer::Level_renderer(const assets::Assets_interface& assets) : Subrenderer(nullptr), m_assets{assets}
{
}

void Level_renderer::init_current_Level()
{
    const auto& level = m_assets.get_loaded_level_render();
    const auto layer_count = level.get_layers().size();
    m_vertices.clear();
    m_vertices.reserve(layer_count);
    for (unsigned int i = 0; i < layer_count; ++i)
    {
        m_vertices.emplace_back(sf::PrimitiveType::Triangles,
                                renderer::constants::WINDOW_SIZE.x / renderer::constants::TILE_SIZE.x *
                                    renderer::constants::WINDOW_SIZE.y / renderer::constants::TILE_SIZE.y * 6);
    }
}

void Level_renderer::render_current_level()
{
    // TODO just render if no camera movement
    const auto& level = m_assets.get_loaded_level_render();
    const auto& layers = level.get_layers();
    const auto& tilesets = level.get_tilesets();
    for (unsigned int i = 0; i < layers.size(); ++i)
    {
        const auto& layer = layers[i];
        if (layer.tiles.empty())
        {
            continue;
        }
        // Assumption / constraint: all tiles in a single layer belong to single tileset
        const auto* tileset = find_tile_set(tilesets, layer.tiles);
        if (tileset == nullptr)
        {
            continue;
        }
        const auto* texture = m_assets.get_texture(tileset->texture_id);
        if (texture == nullptr)
        {
            LOG_F(ERROR, "Could not find texture for tileset!");
            continue;
        }
        m_renderStates.texture = texture;
        render_layer(layer, *tileset, m_vertices[i]);
        draw(m_vertices[i]);
    }
}

}  // namespace renderer
