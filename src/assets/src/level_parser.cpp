#pragma once

#include "level_parser.hpp"

#include <cstdint>
#include <tmxlite/Layer.hpp>
#include <tmxlite/Map.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include <tmxlite/TileLayer.hpp>

#include "asset_path.hpp"
#include "loguru/loguru.hpp"

namespace
{

assets::Asset_id find_asset_id(const std::unordered_map<std::string, assets::Asset_id>& asset_id_map,
                               const std::string& texture_name)
{
    const auto it = std::find_if(asset_id_map.begin(), asset_id_map.end(),
                                 [texture_name](const std::pair<std::string, assets::Asset_id>& value)
                                 { return value.first.find(texture_name) != std::string::npos; });

    if (it == asset_id_map.end())
    {
        return assets::Invalid_asset_id;
    }
    return it->second;
}

std::string get_file_name(const std::string& file_path)
{
    return file_path.substr(file_path.find_last_of("/\\") + 1);
}

}  // namespace

namespace assets
{
namespace level
{
Level Level_parser::load(const std::string& file_path, const std::unordered_map<std::string, Asset_id>& asset_id_map)
{
    const std::string full_path = ASSET_FOLDER_ROOT + file_path;
    tmx::Map map;
    if (!map.load(full_path))
    {
        LOG_F(WARNING, "Could not load level %s", full_path.c_str());
        return Level{};
    }
    Level level;
    const auto& tmx_layers = map.getLayers();
    for (const auto& tmx_layer : tmx_layers)
    {
        if (tmx_layer->getType() == tmx::Layer::Type::Object)
        {
            const auto& object_layer = tmx_layer->getLayerAs<tmx::ObjectGroup>();
            const auto& objects = object_layer.getObjects();
            for (const auto& object : objects)
            {
                LOG_F(WARNING, "Level object parsing missing!");
                // do stuff with object properties
            }
        }
        else if (tmx_layer->getType() == tmx::Layer::Type::Tile)
        {
            const auto& tile_layer = tmx_layer->getLayerAs<tmx::TileLayer>();
            Layer layer;
            for (const auto& tile : tile_layer.getTiles())
            {
                layer.tiles.emplace_back(tile.ID);
            }
            level.add_layer(std::move(layer));
        }
    }

    const auto& tmx_tilesets = map.getTilesets();
    for (const auto& tmx_tileset : tmx_tilesets)
    {
        Tileset tileset;
        tileset.first_gid = tmx_tileset.getFirstGID();
        tileset.last_gid = tmx_tileset.getLastGID();
        const auto& tile_size = tmx_tileset.getTileSize();
        tileset.tile_size = {static_cast<std::int32_t>(tile_size.x), static_cast<std::int32_t>(tile_size.y)};

        for (auto id = tmx_tileset.getFirstGID(); id < tmx_tileset.getLastGID(); ++id)
        {
            const auto* tile = tmx_tileset.getTile(id);
            // TODO probably needs tileoffset, margins and paddings
            math::Float_vector top_left{static_cast<float>(tile->imagePosition.x * tile_size.x),
                                        static_cast<float>(tile->imagePosition.y * tile_size.y)};
            math::Float_vector bottom_right{top_left.x + static_cast<float>(tile_size.x),
                                            top_left.y + static_cast<float>(tile_size.y)};
            tileset.tiles.emplace_back(id, std::vector<math::Float_vector>{top_left,
                                                                           {top_left.x, bottom_right.y},
                                                                           bottom_right,
                                                                           bottom_right,
                                                                           {bottom_right.x, top_left.y},
                                                                           top_left});
        }
        tileset.texture_id = find_asset_id(asset_id_map, get_file_name(tmx_tileset.getImagePath()));
        level.add_tileset(std::move(tileset));
    }
    LOG_F(INFO, "Level loaded from %s", full_path.c_str());
    return level;
}

}  // namespace level
}  // namespace assets