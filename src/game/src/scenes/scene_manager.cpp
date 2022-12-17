#include "scene_manager.hpp"

#include "battle_scene.hpp"
#include "loguru/loguru.hpp"
#include "menu_scene.hpp"

namespace game
{

void Scene_manager::init(entt::registry& registry, renderer::Renderer_interface& renderer)
{
    m_scenes.emplace(Scene_id::UNINITIALIZED, std::make_unique<Scene>(registry, renderer));
    m_scenes.emplace(Scene_id::BATTLE, std::make_unique<Battle_scene>(registry, renderer));
    m_scenes.emplace(Scene_id::MENU, std::make_unique<Menu_scene>(registry, renderer));
}

void Scene_manager::set_battle_scene(const Level& level)
{
    auto& battle_scene = static_cast<Battle_scene&>(*m_scenes[Scene_id::BATTLE]);

    if (m_current_scene == Scene_id::BATTLE)
    {
        if (battle_scene.get_level_id() == level.get_id())
        {
            LOG_F(WARNING, "Tried to initialize same level (%s) twice!", level.get_id().c_str());
            return;
        }
    }
    auto& current_scene = get_current_scene();
    current_scene.dispose();

    m_current_scene = Scene_id::BATTLE;
    battle_scene.init(level);
}

Scene& Scene_manager::get_current_scene()
{
    return *m_scenes[m_current_scene];
}

}  // namespace game