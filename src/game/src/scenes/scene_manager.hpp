#pragma once

#include <entt/entt.hpp>
#include <memory>
#include <unordered_map>

#include "../level.hpp"
#include "scene.hpp"
#include "scene_id.hpp"

namespace renderer
{
class Renderer_interface;
}

namespace assets::level
{
class Level_interface;
}

namespace game
{
class Scene_manager
{
public:
    Scene_manager() = default;

    void init(entt::registry& registry, renderer::Renderer_interface& renderer);

    void set_battle_scene(const assets::level::Level_interface& level_content);

    Scene& get_current_scene();

private:
    std::unordered_map<Scene_id, std::unique_ptr<Scene>> m_scenes;
    Scene_id m_current_scene{Scene_id::UNINITIALIZED};
};
}  // namespace game