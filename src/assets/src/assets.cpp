#include "assets.hpp"

#include "loguru/loguru.hpp"

namespace assets
{

Assets::Assets(std::string asset_folder_root) : m_asset_loader{std::move(asset_folder_root)}
{
}

Load_result Assets::load(const std::string& file_path, const std::string& id)
{
    LOG_F(WARNING, "Asset loading not implemented!");
    const auto asset = m_asset_loader.load(file_path);
    if (!asset)
    {
        LOG_F(WARNING, "Could not load %s from %s", id, file_path);
    }
    return Load_result::Failed;
}

Asset* Assets::get(const std::string& id)
{
    LOG_F(WARNING, "Asset get not implemented!");
    return nullptr;
}

std::unique_ptr<Assets_interface> make_assets(std::string asset_folder_root)
{
    return std::make_unique<Assets>(std::move(asset_folder_root));
}

}  // namespace assets