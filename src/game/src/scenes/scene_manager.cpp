#include "scene_manager.hpp"

#include "battle_scene.hpp"
#include "menu_scene.hpp"

namespace game
{

Scene_manager::Scene_manager()
{
    m_scenes.emplace(Scene_id::UNINITIALIZED, std::make_unique<Scene>());
    m_scenes.emplace(Scene_id::BATTLE, std::make_unique<Battle_scene>());
    m_scenes.emplace(Scene_id::MENU, std::make_unique<Menu_scene>());
}

void Scene_manager::set_battle_scene()
{
    m_current_scene = Scene_id::BATTLE;
}

Scene& Scene_manager::get_current_scene()
{
    return *m_scenes[m_current_scene];
}

}  // namespace game