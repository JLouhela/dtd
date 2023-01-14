#include "scene.hpp"

namespace game
{

Scene::Scene(entt::registry& registry,
             renderer::Renderer_interface& renderer,
             sound::Sound_player_interface& sound_player)
    : m_registry{registry}, m_renderer{renderer}, m_sound_player{sound_player}
{
}

void Scene::dispose()
{
}

void Scene::update(float delta_time)
{
}

}  // namespace game