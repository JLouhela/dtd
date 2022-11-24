#pragma once

#include <memory>
#include <string>

namespace assets
{
class Assets_interface
{
public:
    virtual void load(const std::string& file_path, const std::string& id) = 0;

private:
};

std::unique_ptr<Assets_interface> make_assets();

}  // namespace assets