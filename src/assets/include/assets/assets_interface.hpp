#pragma once

#include <memory>
#include <string>

#include "asset.hpp"

namespace assets
{

enum class Load_result
{
    Ok,
    Failed,
};

class Assets_interface
{
public:
    virtual Load_result load(const std::string& file_path, const std::string& id) = 0;
    virtual Asset* get(const std::string& id) = 0;

private:
};

std::unique_ptr<Assets_interface> make_assets(std::string asset_folder_root);

}  // namespace assets