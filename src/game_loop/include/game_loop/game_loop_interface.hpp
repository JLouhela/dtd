#pragma once

#include <memory>

namespace game
{
class Game_interface;
}

namespace renderer
{
class Renderer_interface;
}

namespace events
{
class Event_handler_interface;
}

namespace game_loop
{

class Game_loop_interface
{
public:
    virtual ~Game_loop_interface() = default;
    virtual void start() = 0;
    virtual void stop() = 0;
};

std::unique_ptr<Game_loop_interface> make_game_loop(game::Game_interface& game,
                                                    renderer::Renderer_interface& renderer,
                                                    events::Event_handler_interface& event_handler);

}  // namespace game_loop