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

}  // namespace level
}  // namespace assets