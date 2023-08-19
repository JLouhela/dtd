#pragma once

#include <entt/entt.hpp>

#include "scene_input_handler.hpp"

namespace renderer
{
class Renderer_interface;
}

namespace sound
{
class Sound_player_interface;
}

namespace input
{
class Input_handler_interface;
}

namespace game
{
class Scene
{
public:
    virtual ~Scene() = default;
    Scene(entt::registry& registry,
          renderer::Renderer_interface& renderer,
          sound::Sound_player_interface& sound_player,
          input::Input_handler_interface& input_handler);
    virtual void dispose();
    virtual void update(float delta_time);

protected:
    entt::registry& m_registry;
    renderer::Renderer_interface& m_renderer;
    sound::Sound_player_interface& m_sound_player;
    Scene_input_handler m_input_handler;

private:
};
}  // namespace game