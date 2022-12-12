#pragma once

#include "assets/level_interface.hpp"

namespace assets
{
class Level : public Level_interface
{
public:
    const std::string& get_id() const final
    {
        return m_id;
    }
    bool operator==(const Level& rhs) const;
    bool operator!=(const Level& rhs) const;

private:
    std::string m_id{"undefined"};
};

}  // namespace assets