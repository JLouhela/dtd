#include "scene.hpp"

namespace game
{

Scene::Scene(entt::registry& registry) : m_registry{registry}
{
}

void Scene::dispose()
{
}

}  // namespace game