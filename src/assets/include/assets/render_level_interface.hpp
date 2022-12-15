#pragma once

#include <string>
#include <vector>

#include "level/layer.hpp"

namespace assets
{

// TODO wrap tmxlite obj
class Render_level_interface
{
public:
    virtual const std::string& get_id() const = 0;
    virtual const std::vector<level::Layer> get_layers() const = 0;
    // TODO oma tileset kopio
    // virtual const std::vector<tmx::Tileset> get_tilesets() const = 0;
    // TODO mitä tarvitaan renderöintiin?
    // tekstuurit
    // firstgid
    // paddingit yms
};

}  // namespace assets