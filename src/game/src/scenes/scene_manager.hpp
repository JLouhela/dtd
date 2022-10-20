#pragma once

#include <memory>
#include <unordered_map>

#include "scene.hpp"
#include "scene_id.hpp"

namespace game
{
class Scene_manager
{
public:
    Scene_manager();

    void set_battle_scene();

    Scene &get_current_scene();

private:
    std::unordered_map<Scene_id, std::unique_ptr<Scene>> m_scenes;
    Scene_id m_current_scene{Scene_id::UNINITIALIZED};
};
}  // namespace game