#pragma once

#include "scene.hpp"

namespace game
{
class Menu_scene : public Scene
{
public:
    Menu_scene(entt::registry& registry,
               renderer::Renderer_interface& renderer,
               sound::Sound_player_interface& sound_player,
               input::Input_handler_interface& input_handler);
};
}  // namespace game