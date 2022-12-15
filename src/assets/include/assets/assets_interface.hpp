#pragma once

#include <memory>
#include <string>

#include "asset_id.hpp"

namespace sf
{
class Texture;
}

namespace assets
{

class Level_interface;
class Render_level_interface;

enum class Load_result
{
    Ok,
    Failed,
};

class Assets_interface
{
public:
    virtual ~Assets_interface() = default;
    virtual Load_result load_texture(const std::string& file_path, const Asset_id& id) = 0;
    virtual Load_result load_level(const std::string& file_path) = 0;
    virtual const sf::Texture* get_texture(const Asset_id& id) const = 0;

    virtual const Level_interface& get_loaded_level_content() const = 0;
    virtual const Render_level_interface& get_loaded_level_render() const = 0;
};

std::unique_ptr<Assets_interface> make_assets();

}  // namespace assets