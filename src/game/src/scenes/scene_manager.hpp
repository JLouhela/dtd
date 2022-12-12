#pragma once

#include <entt/entt.hpp>
#include <memory>
#include <unordered_map>

#include "../level.hpp"
#include "scene.hpp"
#include "scene_id.hpp"

namespace game
{
class Scene_manager
{
public:
    Scene_manager() = default;

    void init(entt::registry& registry);

    void set_battle_scene(const Level& level);

    Scene& get_current_scene();

private:
    std::unordered_map<Scene_id, std::unique_ptr<Scene>> m_scenes;
    Scene_id m_current_scene{Scene_id::UNINITIALIZED};
};
}  // namespace game