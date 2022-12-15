#pragma once

#include <string>

namespace assets
{

class Level_interface
{
public:
    virtual const std::string& get_id() const = 0;
    // TODO mitä tarvitaan logiikkaaN?
    // waypointit
    // spawnihommat (joku tiled metadata -> Json file?)
};

}  // namespace assets