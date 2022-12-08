#pragma once

#include <memory>
#include <string>

#include "SFML/Graphics/Texture.hpp"

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
    virtual ~Assets_interface() = default;
    virtual Load_result load_texture(const std::string& file_path, const std::string& id) = 0;
    virtual const sf::Texture* get_texture(const std::string& id) const = 0;

private:
};

std::unique_ptr<Assets_interface> make_assets();

}  // namespace assets