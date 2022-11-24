#include "assets/assets_interface.hpp"
#include "event_handler/event_handler_interface.hpp"
#include "game/game_interface.hpp"
#include "game_loop/game_loop_interface.hpp"
#include "loguru/loguru.hpp"
#include "renderer/renderer_interface.hpp"

int main(int argc, char* argv[])
{
    loguru::init(argc, argv);
    auto assets = assets::make_assets();
    assets->load("test", "test");
    auto renderer = renderer::make_renderer(*assets);
    auto game = game::make_game(*renderer);
    auto event_handler = events::make_event_handler(renderer->get_window());
    auto game_loop = game_loop::make_game_loop(*game, *renderer, *event_handler);

    game_loop->start();

    return 0;
}