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
    const auto& layers = map.getLayers();
    for (const auto& layer : layers)
    {
        if (layer->getType() == tmx::Layer::Type::Object)
        {
            const auto& objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
            const auto& objects = objectLayer.getObjects();
            for (const auto& object : objects)
            {
                // do stuff with object properties
            }
        }
        else if (layer->getType() == tmx::Layer::Type::Tile)
        {
            const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();
            // read out tile layer properties etc...
        }
    }

    const auto& tilesets = map.getTilesets();
    for (const auto& tileset : tilesets)
    {
        // read out tile set properties, load textures etc...
    }
    return level;
}

}  // namespace assets