#pragma once

#include "level_parser.hpp"

#include <cstdint>
#include <fstream>
#include <nlohmann/json.hpp>
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

void parse_tile_layers(const std::vector<tmx::Layer::Ptr>& tmx_layers,
                       std::uint32_t level_width,
                       assets::level::Level& level)
{
    for (const auto& tmx_layer : tmx_layers)
    {
        if (tmx_layer->getType() == tmx::Layer::Type::Tile)
        {
            const auto& tile_layer = tmx_layer->getLayerAs<tmx::TileLayer>();
            assets::level::Layer layer;
            layer.width = level_width;
            for (const auto& tile : tile_layer.getTiles())
            {
                layer.tiles.emplace_back(tile.ID);
            }
            level.add_layer(std::move(layer));
        }
    }
}

void parse_object_layers(const std::vector<tmx::Layer::Ptr>& tmx_layers, assets::level::Level& level)
{
    for (const auto& tmx_layer : tmx_layers)
    {
        if (tmx_layer->getType() == tmx::Layer::Type::Object)
        {
            const auto& object_layer = tmx_layer->getLayerAs<tmx::ObjectGroup>();
            const auto& objects = object_layer.getObjects();
            for (const auto& object : objects)
            {
                LOG_F(WARNING, "Level object parsing missing -> no waypoints!");
                // TODO store waypoints to levels
            }
        }
    }
}

void parse_tilesets(const std::vector<tmx::Tileset>& tmx_tilesets,
                    const std::unordered_map<std::string, assets::Asset_id>& asset_id_map,
                    assets::level::Level& level)
{
    for (const auto& tmx_tileset : tmx_tilesets)
    {
        assets::level::Tileset tileset;
        tileset.first_gid = tmx_tileset.getFirstGID();
        tileset.last_gid = tmx_tileset.getLastGID();
        const auto& tile_size = tmx_tileset.getTileSize();
        tileset.tile_size = {static_cast<std::int32_t>(tile_size.x), static_cast<std::int32_t>(tile_size.y)};

        for (auto id = tmx_tileset.getFirstGID(); id < tmx_tileset.getLastGID(); ++id)
        {
            const auto* tile = tmx_tileset.getTile(id);
            // TODO probably needs tileoffset, margins and paddings
            math::Float_vector top_left{static_cast<float>(tile->imagePosition.x),
                                        static_cast<float>(tile->imagePosition.y)};
            math::Float_vector bottom_right{top_left.x + static_cast<float>(tile_size.x),
                                            top_left.y + static_cast<float>(tile_size.y)};
            tileset.tiles.emplace_back(id, std::vector<math::Float_vector>{top_left,
                                                                           {bottom_right.x, top_left.y},
                                                                           bottom_right,
                                                                           bottom_right,
                                                                           {top_left.x, bottom_right.y},
                                                                           top_left});
        }
        tileset.texture_id = find_asset_id(asset_id_map, get_file_name(tmx_tileset.getImagePath()));
        level.add_tileset(std::move(tileset));
    }
}

const tmx::Property* get_property(const std::vector<tmx::Property>& props, const std::string& id)
{
    const auto it = std::find_if(std::begin(props), std::end(props),
                                 [id](const tmx::Property& prop) { return prop.getName() == id; });
    return it == std::end(props) ? nullptr : &(*it);
}

const tmx::Property* get_metadata_property(const std::vector<tmx::Property>& props)
{
    return get_property(props, "metadata_file");
}

void parse_properties(const tmx::Map& map, assets::level::Level& level)
{
    const auto& props = map.getProperties();
    const auto* meta_data_prop = get_metadata_property(props);
    if (!meta_data_prop)
    {
        LOG_F(WARNING, "Could not find metadata property for the level %s!", level.get_id().c_str());
        return;
    }
    const auto& metadata_file = meta_data_prop->getStringValue();
    const std::string json_path = assets::ASSET_FOLDER_ROOT + "levels/" + metadata_file;
    std::ifstream json_stream{json_path};
    const auto data = nlohmann::json::parse(json_stream);
    const auto waves = data["waves"];
    for (std::uint32_t wave_idx = 0; wave_idx < waves.size(); ++wave_idx)
    {
        const auto& wave = waves[wave_idx];
        assets::level::Enemy_wave enemy_wave;

        const auto& enemies = wave["enemies"];
        for (std::uint32_t enemy_idx = 0; enemy_idx < enemies.size(); ++enemy_idx)
        {
            const auto& enemy = enemies[enemy_idx];
            enemy_wave.enemies.emplace_back(enemy["type"], enemy["count"], enemy["spawn_time"]);
        }
        level.add_wave(enemy_wave);
    }
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
    level.set_id(file_path);
    const auto& tmx_layers = map.getLayers();
    parse_tile_layers(tmx_layers, map.getTileCount().x, level);
    parse_object_layers(tmx_layers, level);

    const auto& tmx_tilesets = map.getTilesets();
    parse_tilesets(tmx_tilesets, asset_id_map, level);
    parse_properties(map, level);

    LOG_F(INFO, "Level loaded from %s", full_path.c_str());
    return level;
}

}  // namespace level
}  // namespace assets