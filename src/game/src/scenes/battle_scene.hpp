#pragma once

#include <string>

#include "level.hpp"
#include "scene.hpp"

namespace game
{
class Battle_scene : public Scene
{
public:
    Battle_scene(entt::registry& registry);

    void dispose() final;

    void init(const std::string& level);
    const std::string& get_level_id();

private:
    Level m_level;
};
}  // namespace game