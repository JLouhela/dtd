#pragma once

#include <string>

namespace assets
{

// TODO wrap tmxlite obj
class Level_interface
{
public:
    virtual const std::string& get_id() const = 0;
};

}  // namespace assets