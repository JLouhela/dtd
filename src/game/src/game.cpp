#include "game.hpp"

#include "constants.hpp"
#include "level.hpp"
#include "loguru/loguru.hpp"

namespace game
{

Game::Game(renderer::Renderer_interface& renderer, assets::Assets_interface& assets)
    : m_renderer{renderer}, m_assets{assets}, m_system_manager{m_registry, m_renderer}
{
    // TODO init registry properly
    m_scene_manager.init(m_registry);

    // Assuming current level has been loaded OK before game ctor is called
    const auto& level_asset = assets.get_current_level();
    Level level(level_asset);
    m_scene_manager.set_battle_scene(level);
}

void Game::update(std::int32_t delta_time)
{
    m_system_manager.execute();
}

std::unique_ptr<Game_interface> make_game(renderer::Renderer_interface& renderer, assets::Assets_interface& assets)
{
    return std::make_unique<Game>(renderer, assets);
}

}  // namespace game