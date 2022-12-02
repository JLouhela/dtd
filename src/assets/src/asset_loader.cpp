#include "asset_loader.hpp"

#include "loguru/loguru.hpp"

namespace assets
{
Asset_loader::Asset_loader(std::string root_path) : m_root_path(root_path)
{
}

std::unique_ptr<sf::Texture> Asset_loader::load_texture(const std::string& file_path)
{
    sf::Texture texture;
    const std::string full_path = m_root_path + '/' + file_path;
    if (!texture.loadFromFile(full_path))
    {
        LOG_F(WARNING, "Could not load texture from %s", full_path.c_str());
        return nullptr;
    }
    return std::make_unique<sf::Texture>(texture);
}

}  // namespace assets