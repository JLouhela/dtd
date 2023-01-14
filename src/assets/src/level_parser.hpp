#pragma once

#include <string>
#include <unordered_map>

#include "level.hpp"
#include "types/asset_id.hpp"

namespace assets
{
namespace level
{

namespace Level_parser
{

Level load(const std::string& file_path, const std::unordered_map<std::string, types::Asset_id>& asset_id_map);

}
}  // namespace level
}  // namespace assets