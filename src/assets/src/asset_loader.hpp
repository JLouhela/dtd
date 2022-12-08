#pragma once

#include <memory>
#include <string>

#include "SFML/Graphics/Texture.hpp"

namespace assets
{
class Asset_loader
{
public:
    Asset_loader();

    struct TextureLoadResult
    {
        bool success{false};
        sf::Texture texture;
    };
    TextureLoadResult load_texture(const std::string& file_path);
};

}  // namespace assets