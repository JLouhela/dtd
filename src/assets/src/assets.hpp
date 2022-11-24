
#pragma once

#include "asset_loader.hpp"
#include "assets/assets_interface.hpp"

namespace assets
{
class Assets : public Assets_interface
{
public:
    virtual void load(const std::string& file_path, const std::string& id) override;

private:
    Asset_loader m_asset_loader;
#ifdef DEBUG
private:
    void watch(const std::string& id);
#endif
};

}  // namespace assets