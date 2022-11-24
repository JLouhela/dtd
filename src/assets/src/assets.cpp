#include "assets.hpp"

#include "loguru/loguru.hpp"

namespace assets
{

Assets::Assets(const std::string& asset_folder_root) : m_folder_root{std::move(asset_folder_root)}
{
}

void Assets::load(const std::string& file_path, const std::string& id)
{
    LOG_F(WARNING, "Asset loading not implemented!");
}

std::unique_ptr<Assets_interface> make_assets(std::string asset_folder_root)
{
    return std::make_unique<Assets>(std::move(asset_folder_root));
}

}  // namespace assets