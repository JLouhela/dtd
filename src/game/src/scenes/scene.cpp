#include "scene.hpp"

namespace game
{

Scene::Scene(entt::registry& registry,
             Camera& camera,
             renderer::Renderer_interface& renderer,
             sound::Sound_player_interface& sound_player,
             input::Input_handler_interface& input_handler)
    : m_registry{registry},
      m_camera{camera},
      m_renderer{renderer},
      m_sound_player{sound_player},
      m_input_handler{input_handler}
{
}

void Scene::dispose()
{
}

void Scene::update(float delta_time)
{
}

}  // namespace game