#include "game_loop.hpp"

using namespace game_loop;

Game_loop::Game_loop(game::Game_interface& game, renderer::Renderer_interface& renderer)
    : m_game{game}, m_renderer{renderer}
{
}

std::unique_ptr<Game_loop_interface> make_game_loop(game::Game_interface& game, renderer::Renderer_interface& renderer)
{
    return std::make_unique<Game_loop>(game, renderer);
}