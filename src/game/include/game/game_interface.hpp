#pragma once

#include <cstdint>
#include <memory>

namespace assets
{
class Assets_interface;
}
namespace renderer
{
class Renderer_interface;
}
namespace sound
{
class Sound_player_interface;
}
namespace events
{
class Event_handler_interface;
}
namespace input
{
class Input_handler_interface;
}

namespace game
{

class Game_interface
{
public:
    virtual ~Game_interface() = default;

    virtual void update(float delta_time) = 0;
};

std::unique_ptr<Game_interface> make_game(renderer::Renderer_interface& renderer_interface,
                                          assets::Assets_interface& assets,
                                          sound::Sound_player_interface& sound_player,
                                          input::Input_handler_interface& input_handler);

}  // namespace game
