#pragma once

#include <string>
#include <unordered_map>

#include "assets/asset_id.hpp"
#include "level.hpp"

namespace assets
{
namespace level
{

namespace Level_parser
{

Level load(const std::string& file_path, const std::unordered_map<std::string, Asset_id>& asset_id_map);

}
}  // namespace level
}  // namespace assets