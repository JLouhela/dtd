#pragma once

#include <memory>
#include <string>

#include "types/asset_id.hpp"

namespace sf
{
class Texture;
class SoundBuffer;
}  // namespace sf

namespace assets
{
namespace level
{
class Level_interface;
class Render_level_interface;
}  // namespace level

enum class Load_result
{
    Ok,
    Failed,
};

class Assets_interface
{
public:
    virtual ~Assets_interface() = default;
    virtual Load_result load_texture(const std::string& file_path, const types::Asset_id& id) = 0;
    virtual Load_result load_sound(const std::string& file_path, const types::Asset_id& id) = 0;
    virtual Load_result load_level(const std::string& file_path) = 0;
    virtual const sf::Texture* get_texture(const types::Asset_id& id) const = 0;
    virtual const sf::SoundBuffer* get_sound_buffer(const types::Asset_id& id) const = 0;

    virtual const level::Level_interface& get_loaded_level_content() const = 0;
    virtual const level::Render_level_interface& get_loaded_level_render() const = 0;
};

std::unique_ptr<Assets_interface> make_assets();

}  // namespace assets