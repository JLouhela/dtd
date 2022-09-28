#include "game.hpp"

namespace game
{

Game::Game()
{
}

void Game::update(std::int32_t delta_time)
{
    m_system_manager.execute();
}

std::unique_ptr<Game_interface> make_game()
{
    return std::make_unique<Game>();
}

}