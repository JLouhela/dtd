
#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "asset_loader.hpp"
#include "assets/assets_interface.hpp"

namespace assets
{
class Assets : public Assets_interface
{
public:
    Assets(std::string asset_folder_root);
    Load_result load_texture(const std::string& file_path, const std::string& id) final;
    sf::Texture* get_texture(const std::string& id) const final;

private:
    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> m_textures;
    Asset_loader m_asset_loader;
};

}  // namespace assets