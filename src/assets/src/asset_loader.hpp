#pragma once

#include <memory>
#include <string>

#include "assets/asset.hpp"

namespace assets
{
class Asset_loader
{
public:
    Asset_loader(std::string root_path);
    std::unique_ptr<Asset> load(const std::string& file_path);

private:
    std::string m_root_path;
};

}  // namespace assets