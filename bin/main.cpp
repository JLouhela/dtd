#include "assets/assets_interface.hpp"
#include "assets/level/levels.hpp"
#include "event_handler/event_handler_interface.hpp"
#include "game/game_interface.hpp"
#include "game_loop/game_loop_interface.hpp"
#include "loguru/loguru.hpp"
#include "renderer/renderer_interface.hpp"
#include "sound_player/sound_player_interface.hpp"

namespace
{
void load_assets(assets::Assets_interface& assets)
{
    assets.load_texture("sprites/towerDefense_tilesheet.png", "td_tilesheet");
    assets.load_sound("sound/effects/explosion.wav", "explosion_wav");
    assets.load_sound("sound/effects/explosion.ogg", "explosion_ogg");
    const std::string level_file = "levels/" + assets::levels::level_1;
    assets.load_level(level_file);
}
}  // namespace

int main(int argc, char* argv[])
{
    loguru::init(argc, argv);
    auto assets = assets::make_assets();
    load_assets(*assets);

    auto renderer = renderer::make_renderer(*assets);
    auto sound_player = sound::make_sound_player(*assets);
    renderer->get_level_renderer().init_current_Level();

    auto game = game::make_game(*renderer, *assets, *sound_player);
    auto event_handler = events::make_event_handler(renderer->get_window());
    auto game_loop = game_loop::make_game_loop(*game, *renderer, *event_handler);

    game_loop->start();

    return 0;
}