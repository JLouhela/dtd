#pragma once

#include <memory>
#include <string>

#include "SFML/Graphics/Texture.hpp"

namespace assets
{
class Asset_loader
{
public:
    Asset_loader(std::string root_path);
    std::unique_ptr<sf::Texture> load_texture(const std::string& file_path);

private:
    std::string m_root_path;
};

}  // namespace assets