#include "game/game_interface.hpp"
#include "game_loop/game_loop_interface.hpp"
#include "loguru/loguru.hpp"
#include "renderer/renderer_interface.hpp"

int main(int argc, char* argv[])
{
    loguru::init(argc, argv);
    auto game = game::make_game();
    auto renderer = renderer::make_renderer();
    auto game_loop = game_loop::make_game_loop(*game, *renderer);

    game_loop->start();

    return 0;
}