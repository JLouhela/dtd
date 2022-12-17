#pragma once

#include "level_parser.hpp"

#include <tmxlite/Layer.hpp>
#include <tmxlite/Map.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include <tmxlite/TileLayer.hpp>

#include "asset_path.hpp"
#include "loguru/loguru.hpp"

namespace assets
{
namespace level
{

Level Level_parser::load(const std::string& file_path)
{
    const std::string full_path = ASSET_FOLDER_ROOT + file_path;
    LOG_F(WARNING, "Load level NOT really implemented!");

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

    const auto& tilesets = map.getTilesets();
    for (const auto& tileset : tilesets)
    {
        // read out tile set properties, load textures etc...
    }
    LOG_F(INFO, "Level loaded from %s", full_path.c_str());
    return level;
}

}  // namespace level
}  // namespace assets