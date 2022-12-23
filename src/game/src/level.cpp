#include "level.hpp"

#include "loguru/loguru.hpp"

namespace game
{
Level::Level(const assets::level::Level_interface& source) : m_content{source}
{
}

const std::string& Level::get_id() const
{
    return m_content.get_id();
}
const std::vector<assets::level::Enemy_wave>& Level::get_waves() const
{
    return m_content.get_waves();
}
const std::vector<assets::level::Waypoints>& Level::get_waypoints() const
{
    return m_content.get_waypoints();
}

}  // namespace game