#pragma once

#include "scene.hpp"

namespace game
{
class Menu_scene : public Scene
{
public:
    Menu_scene(entt::registry& registry, renderer::Renderer_interface& renderer);
};
}  // namespace game