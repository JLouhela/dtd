#include "sound_cache.hpp"

#include <algorithm>

#include "SFML/Audio/Sound.hpp"
#include "assets/assets_interface.hpp"
#include "loguru/loguru.hpp"

namespace sound
{
Sound_cache::Sound_cache(const assets::Assets_interface& assets) : m_assets(assets)
{
    add_sound(Sound_id::Basic_projectile_hit_1, "explosion_ogg");
}

sf::Sound* Sound_cache::get_sound(const Sound_id& id)
{
    auto it = m_sounds.find(id);
    if (it == std::end(m_sounds))
    {
        LOG_F(ERROR, "Could not find sound %d", static_cast<int>(id));
        return nullptr;
    }
    return &(it->second);
}

void Sound_cache::add_sound(const Sound_id& id, const types::Asset_id& asset_id)
{
    const auto* buffer = m_assets.get_sound_buffer(asset_id);
    if (!buffer)
    {
        LOG_F(WARNING, "Could not get sound buffer for asset id %s", asset_id.c_str());
        return;
    }
    m_sounds.emplace(id, sf::Sound{*buffer});
    m_sounds.at(id).setVolume(50.0);
}
}  // namespace sound
