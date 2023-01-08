#include "asset_loader.hpp"

#include "asset_path.hpp"
#include "loguru/loguru.hpp"

namespace assets
{
Asset_loader::Asset_loader()
{
}

Asset_loader::Texture_load_result Asset_loader::load_texture(const std::string& file_path)
{
    sf::Texture texture;
    const std::string full_path = ASSET_FOLDER_ROOT + file_path;
    if (!texture.loadFromFile(full_path))
    {
        LOG_F(WARNING, "Could not load texture from %s", full_path.c_str());
        return {};
    }
    return {true, texture};
}

Asset_loader::Sound_load_result Asset_loader::load_sound(const std::string& file_path)
{
    sf::SoundBuffer sound_buffer;
    const std::string full_path = ASSET_FOLDER_ROOT + file_path;
    if (!sound_buffer.loadFromFile(full_path))
    {
        LOG_F(WARNING, "Could not load sound from %s", full_path.c_str());
        return {};
    }
    return {true, sound_buffer};
}

}  // namespace assets