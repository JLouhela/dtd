#pragma once

#include <memory>
#include <string>

#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Graphics/Texture.hpp"

namespace assets
{
class Asset_loader
{
public:
    Asset_loader();

    struct Texture_load_result
    {
        bool success{false};
        sf::Texture texture;
    };
    Texture_load_result load_texture(const std::string& file_path);

    struct Sound_load_result
    {
        bool success{false};
        sf::SoundBuffer sound_buffer;
    };
    Sound_load_result load_sound(const std::string& file_path);
};

}  // namespace assets