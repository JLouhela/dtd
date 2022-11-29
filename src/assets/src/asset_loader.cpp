#include "asset_loader.hpp"

#include "loguru/loguru.hpp"

namespace assets
{
Asset_loader::Asset_loader(std::string root_path)
{
}

std::unique_ptr<Asset> Asset_loader::load(const std::string& file_path)
{
    // TODO load sfml asset -> wrap to Asset
    LOG_F(WARNING, "Asset loader: asset load not implemented!");
    return nullptr;
}

}  // namespace assets