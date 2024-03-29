#include "level.hpp"

namespace assets
{

namespace level
{

void Level::set_id(std::string id)
{
    m_id = std::move(id);
}

bool Level::operator==(const Level& rhs) const
{
    return m_id == rhs.get_id();
}
bool Level::operator!=(const Level& rhs) const
{
    return !(m_id == rhs.get_id());
}

void Level::add_layer(Layer layer)
{
    m_layers.emplace_back(std::move(layer));
}

void Level::add_tileset(Tileset tileset)
{
    m_tilesets.emplace_back(std::move(tileset));
}

void Level::add_wave(Enemy_wave wave)
{
    m_waves.emplace_back(std::move(wave));
}

void Level::add_waypoints(Waypoints waypoints)
{
    m_waypoints.emplace_back(std::move(waypoints));
}

}  // namespace level
}  // namespace assets