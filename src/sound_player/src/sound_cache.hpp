#pragma once

#include <unordered_map>

#include "sound_player/sound_id.hpp"
#include "types/asset_id.hpp"

namespace sf
{
class Sound;
class SoundBuffer;
}  // namespace sf

namespace assets
{
class Assets_interface;
}
namespace sound
{

class Sound_cache
{
public:
    explicit Sound_cache(const assets::Assets_interface& assets);
    sf::Sound* get_sound(const Sound_id& id);

private:
    void add_sound(const Sound_id& id, const types::Asset_id& asset_id);

    std::unordered_map<Sound_id, sf::Sound> m_sounds;
    const assets::Assets_interface& m_assets;
};

}  // namespace sound
