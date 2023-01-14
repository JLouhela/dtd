#pragma once

#include "sound_player/sound_player_Interface.hpp"

namespace sound
{
class Sound_player : public Sound_player_interface
{
public:
    Sound_player(const assets::Assets_interface& assets);
    void play_sound(const Sound_id& sound_id) const final;

private:
    const assets::Assets_interface& m_assets;
};

}  // namespace sound