#pragma once

#include <string>

#include "assets/level_interface.hpp"

namespace game
{
class Level
{
public:
    Level() = default;
    explicit Level(const assets::level::Level_interface& source);

    const std::string& get_id() const;
    const std::vector<assets::level::Enemy_wave>& get_waves() const;
    const std::vector<assets::level::Waypoints>& get_waypoints() const;

private:
    const assets::level::Level_interface& m_content;
    std::string m_cur_level_id{"undefined"};
};
}  // namespace game