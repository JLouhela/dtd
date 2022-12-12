#pragma once

#include <string>

#include "level.hpp"

namespace assets
{
namespace Level_parser
{

Level load(const std::string& file_path);

}
}  // namespace assets