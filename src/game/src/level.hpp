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

    const std::string& get_id() const
    {
        return m_cur_level_id;
    }

private:
    std::string m_cur_level_id{"undefined"};
};
}  // namespace game