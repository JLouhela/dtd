#pragma once

#include <string>
#include <tmxlite/Layer.hpp>
#include <tmxlite/Map.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include <tmxlite/TileLayer.hpp>

namespace game
{
class Level_parser
{
public:
    void load(const std::string& file_name);

private:
};
}  // namespace game