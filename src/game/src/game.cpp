#include "game.hpp"

#include "assets/assets_interface.hpp"
#include "constants.hpp"
#include "level.hpp"
#include "loguru/loguru.hpp"

namespace game
{

Game::Game(renderer::Renderer_interface& renderer,
           assets::Assets_interface& assets,
           sound::Sound_player_interface& sound_player,
           input::Input_handler_interface& input_handler)
    : m_renderer{renderer}, m_assets{assets}, m_sound_player{sound_player}, m_input_handler{input_handler}
{
    // TODO init registry properly
    m_scene_manager.init(m_registry, m_renderer, m_sound_player, input_handler);

    // Assuming current level has been loaded OK before game ctor is called
    const auto& level_asset = assets.get_loaded_level_content();
    m_scene_manager.set_battle_scene(level_asset);
}

void Game::update(float delta_time)
{
    m_scene_manager.get_current_scene().update(delta_time);
}

std::unique_ptr<Game_interface> make_game(renderer::Renderer_interface& renderer,
                                          assets::Assets_interface& assets,
                                          sound::Sound_player_interface& sound_player,
                                          input::Input_handler_interface& input_handler)
{
    return std::make_unique<Game>(renderer, assets, sound_player, input_handler);
}

}  // namespace game