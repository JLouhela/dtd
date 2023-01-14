#include "sound_player.hpp"

#include "loguru/loguru.hpp"

namespace sound
{

Sound_player::Sound_player(const assets::Assets_interface& assets) : m_assets(assets)
{
}

void Sound_player::play_sound(const Sound_id& sound_id) const
{
    LOG_F(INFO, "PLAY SOUND: %d", (int)sound_id);
}

std::unique_ptr<Sound_player_interface> make_sound_player(const assets::Assets_interface& assets)
{
    return std::make_unique<Sound_player>(assets);
}

}  // namespace sound