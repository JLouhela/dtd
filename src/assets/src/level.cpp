#pragma once

#include "level.hpp"

namespace assets
{

namespace level
{

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

}  // namespace level
}  // namespace assets