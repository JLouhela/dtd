#include "sound_player.hpp"

#include "SFML/Audio.hpp"
#include "assets/assets_interface.hpp"
#include "loguru/loguru.hpp"

namespace sound

{

Sound_player::Sound_player(const assets::Assets_interface& assets) : m_sound_cache{assets}, m_assets{assets}
{
}

void Sound_player::play_sound(const Sound_id& sound_id)
{
    auto* sound = m_sound_cache.get_sound(sound_id);
    if (!sound)
    {
        LOG_F(WARNING, "Could not find sound with sound id %d", static_cast<int>(sound_id));
        return;
    }
    sound->play();
}

std::unique_ptr<Sound_player_interface> make_sound_player(const assets::Assets_interface& assets)
{
    return std::make_unique<Sound_player>(assets);
}

}  // namespace sound