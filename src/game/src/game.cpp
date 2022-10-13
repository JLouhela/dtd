#include "game.hpp"

#include "loguru/loguru.hpp"

namespace
{
void draw_debug_grid()
{
}

}  // namespace

namespace game
{

Game::Game(renderer::Renderer_interface& renderer) : m_renderer{renderer}
{
}

void Game::update(std::int32_t delta_time)
{
#ifdef DEBUG
    auto& debug_renderer = m_renderer.get_debug_renderer();
    debug_renderer.draw_line({50, 50}, {300, 300});
    debug_renderer.draw_line({50, 300}, {300, 50});
#endif
    m_system_manager.execute();
}

std::unique_ptr<Game_interface> make_game(renderer::Renderer_interface& renderer)
{
    return std::make_unique<Game>(renderer);
}

}  // namespace game