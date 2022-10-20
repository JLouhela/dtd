#pragma once

#include <string>

namespace game
{
class Level
{
public:
    Level() = default;

    void load(const std::string& level_file);
};
}  // namespace game