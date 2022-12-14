#include "scene.hpp"

namespace game
{

Scene::Scene(entt::registry& registry, renderer::Renderer_interface& renderer)
    : m_registry{registry}, m_renderer{renderer}
{
}

void Scene::dispose()
{
}

void Scene::update(float delta_time)
{
}

}  // namespace game