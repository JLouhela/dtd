#include "game.hpp"

#include "constants.hpp"
#include "loguru/loguru.hpp"

namespace game
{

Game::Game(renderer::Renderer_interface& renderer) : m_renderer{renderer}
{
    // TODO init registry properly
    m_scene_manager.init(m_registry);
    m_scene_manager.set_battle_scene(constants::levels::level_1);
}

void Game::update(std::int32_t delta_time)
{
#ifdef DEBUG
    m_renderer.get_debug_renderer().draw_grid(constants::TILE_SIZE);
#endif
    m_system_manager.execute();
}

std::unique_ptr<Game_interface> make_game(renderer::Renderer_interface& renderer)
{
    return std::make_unique<Game>(renderer);
}

}  // namespace game