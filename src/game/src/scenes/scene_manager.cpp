#include "scene_manager.hpp"

#include "../constants.hpp"
#include "battle_scene.hpp"
#include "loguru/loguru.hpp"
#include "menu_scene.hpp"
#include "renderer/renderer_interface.hpp"

namespace game
{

Scene_manager::Scene_manager() : m_camera{constants::TILE_SIZE}
{
}

void Scene_manager::init(entt::registry& registry,
                         renderer::Renderer_interface& renderer,
                         sound::Sound_player_interface& sound_player,
                         input::Input_handler_interface& input_handler)
{
    m_camera.set_viewport_size(renderer.get_window_size());
    m_scenes.emplace(Scene_id::UNINITIALIZED,
                     std::make_unique<Scene>(registry, m_camera, renderer, sound_player, input_handler));
    m_scenes.emplace(Scene_id::BATTLE,
                     std::make_unique<Battle_scene>(registry, m_camera, renderer, sound_player, input_handler));
    m_scenes.emplace(Scene_id::MENU,
                     std::make_unique<Menu_scene>(registry, m_camera, renderer, sound_player, input_handler));
}

void Scene_manager::set_battle_scene(const assets::level::Level_interface& level_content)
{
    auto& battle_scene = static_cast<Battle_scene&>(*m_scenes[Scene_id::BATTLE]);

    if (m_current_scene == Scene_id::BATTLE)
    {
        if (battle_scene.get_level_id() == level_content.get_id())
        {
            LOG_F(WARNING, "Tried to initialize same level (%s) twice!", level_content.get_id().c_str());
            return;
        }
    }
    auto& current_scene = get_current_scene();
    current_scene.dispose();

    m_current_scene = Scene_id::BATTLE;
    battle_scene.init(level_content);
}

Scene& Scene_manager::get_current_scene()
{
    return *m_scenes[m_current_scene];
}

}  // namespace game