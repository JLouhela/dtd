#pragma once

#include "level.hpp"

namespace assets
{
bool Level::operator==(const Level& rhs) const
{
    return m_id == rhs.get_id();
}
bool Level::operator!=(const Level& rhs) const
{
    return !(m_id == rhs.get_id());
}
}  // namespace assets