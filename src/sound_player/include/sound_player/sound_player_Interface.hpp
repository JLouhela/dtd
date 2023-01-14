#pragma once

#include <memory>

#include "sound_id.hpp"

namespace assets
{
class Assets_interface;
}

namespace sound
{

class Sound_player_interface
{
public:
    virtual ~Sound_player_interface() = default;

    virtual void play_sound(const Sound_id& sound_id) const = 0;
};

std::unique_ptr<Sound_player_interface> make_sound_player(const assets::Assets_interface& assets);

}  // namespace sound