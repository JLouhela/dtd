#include "game.hpp"

#include "constants.hpp"
#include "level.hpp"
#include "loguru/loguru.hpp"

namespace game
{

Game::Game(renderer::Renderer_interface& renderer, assets::Assets_interface& assets)
    : m_renderer{renderer}, m_assets{assets}
{
    // TODO init registry properly
    m_scene_manager.init(m_registry, m_renderer);

    // Assuming current level has been loaded OK before game ctor is called
    const auto& level_asset = assets.get_loaded_level_content();
    m_scene_manager.set_battle_scene(level_asset);
}

void Game::update(float delta_time)
{
    m_scene_manager.get_current_scene().update(delta_time);
}

std::unique_ptr<Game_interface> make_game(renderer::Renderer_interface& renderer, assets::Assets_interface& assets)
{
    return std::make_unique<Game>(renderer, assets);
}

}  // namespace game