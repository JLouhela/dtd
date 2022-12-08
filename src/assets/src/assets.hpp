
#pragma once

#include <string>
#include <unordered_map>

#include "asset_loader.hpp"
#include "assets/assets_interface.hpp"

namespace assets
{
class Assets : public Assets_interface
{
public:
    Assets();
    Load_result load_texture(const std::string& file_path, const std::string& id) final;
    const sf::Texture* get_texture(const std::string& id) const final;

private:
    void create_color_textures();
    std::unordered_map<std::string, sf::Texture> m_textures;
    Asset_loader m_asset_loader;
};

}  // namespace assets