#include "asset_loader.hpp"

#include "asset_path.hpp"
#include "loguru/loguru.hpp"

namespace assets
{
Asset_loader::Asset_loader()
{
}

Asset_loader::TextureLoadResult Asset_loader::load_texture(const std::string& file_path)
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

}  // namespace assets