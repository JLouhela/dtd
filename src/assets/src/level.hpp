#pragma once

#include <vector>

#include "assets/level/layer.hpp"
#include "assets/level/tileset.hpp"
#include "assets/level_interface.hpp"
#include "assets/render_level_interface.hpp"

namespace assets
{
namespace level
{

class Level : public Level_interface, public Render_level_interface
{
public:
    const std::string& get_id() const final
    {
        return m_id;
    }
    const std::vector<Layer> get_layers() const final
    {
        return m_layers;
    }
    const std::vector<Tileset> get_tilesets() const final
    {
        return m_tilesets;
    }

    void set_id(std::string id);
    void add_layer(Layer layer);
    void add_tileset(Tileset tileset);
    bool operator==(const Level& rhs) const;
    bool operator!=(const Level& rhs) const;

private:
    std::string m_id{"undefined"};
    std::vector<Layer> m_layers;
    std::vector<Tileset> m_tilesets;
};
}  // namespace level

}  // namespace assets