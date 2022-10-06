#pragma once

#include "event_handler/event_handler_interface.hpp"
#include "game/game_interface.hpp"
#include "game_loop/game_loop_interface.hpp"
#include "renderer/renderer_interface.hpp"

namespace game_loop
{

class Game_loop : public Game_loop_interface
{
public:
    Game_loop(game::Game_interface& game,
              renderer::Renderer_interface& renderer,
              events::Event_handler_interface& event_handler);
    ~Game_loop() final = default;

    void start() final;
    void stop() final;

private:
    void run();

    game::Game_interface& m_game;
    renderer::Renderer_interface& m_renderer;
    events::Event_handler_interface& m_event_handler;

    bool m_running{false};
};

}  // namespace game_loop