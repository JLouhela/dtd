#pragma once

#include <memory>
#include <string>

namespace sf
{
class Texture;
}

namespace assets
{

class Level_interface;
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
    virtual Load_result load_level(const std::string& file_path) = 0;
    virtual const sf::Texture* get_texture(const std::string& id) const = 0;
    virtual const Level_interface& get_current_level() const = 0;
};

std::unique_ptr<Assets_interface> make_assets();

}  // namespace assets