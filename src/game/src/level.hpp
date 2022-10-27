#pragma once

#include <string>

namespace game
{
class Level
{
public:
    Level() = default;

    void load(const std::string& level_file);

    const std::string& get_id()
    {
        return m_cur_level_id;
    }

private:
    std::string m_cur_level_id{"undefined"};
};
}  // namespace game