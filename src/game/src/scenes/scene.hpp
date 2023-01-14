#pragma once

#include <entt/entt.hpp>

namespace renderer
{
class Renderer_interface;
}

namespace sound
{
class Sound_player_interface;
}

namespace game
{
class Scene
{
public:
    virtual ~Scene() = default;
    Scene(entt::registry& registry,
          renderer::Renderer_interface& renderer,
          sound::Sound_player_interface& sound_player);
    virtual void dispose();
    virtual void update(float delta_time);

protected:
    entt::registry& m_registry;
    renderer::Renderer_interface& m_renderer;
    sound::Sound_player_interface& m_sound_player;

private:
};
}  // namespace game