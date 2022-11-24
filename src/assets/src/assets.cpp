#include "assets.hpp"

#include "loguru/loguru.hpp"

namespace assets
{

void Assets::load(const std::string& file_path, const std::string& id)
{
    LOG_F(WARNING, "Asset loading not implemented!");
}

std::unique_ptr<Assets_interface> make_assets()
{
    return std::make_unique<Assets>();
}

}  // namespace assets