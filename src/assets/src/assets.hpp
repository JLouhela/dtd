
#pragma once

#include <string>

#include "asset_loader.hpp"
#include "assets/assets_interface.hpp"

namespace assets
{
class Assets : public Assets_interface
{
public:
    Assets(const std::string& asset_folder_root);
    virtual void load(const std::string& file_path, const std::string& id) override;

private:
    Asset_loader m_asset_loader;
    std::string m_folder_root;
#ifdef DEBUG
private:
    void watch(const std::string& id);
#endif
};

}  // namespace assets