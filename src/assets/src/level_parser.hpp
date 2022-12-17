#pragma once

#include <string>

#include "level.hpp"

namespace assets
{
namespace level
{

namespace Level_parser
{

Level load(const std::string& file_path);

}
}  // namespace level
}  // namespace assets