#pragma once

#include <string>

#include "level.hpp"
#include "scene.hpp"

namespace game
{
class Battle_scene : public Scene
{
public:
    Battle_scene() = default;

    void init(const std::string& level);

private:
    Level m_level;
};
}  // namespace game