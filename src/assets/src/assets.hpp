
#pragma once

#include <string>
#include <unordered_map>

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "asset_loader.hpp"
#include "assets/assets_interface.hpp"
#include "level.hpp"

namespace assets
{
class Assets : public Assets_interface
{
public:
    Assets();
    Load_result load_texture(const std::string& file_path, const types::Asset_id& id) final;
    Load_result load_sound(const std::string& file_path, const types::Asset_id& id) final;
    Load_result load_level(const std::string& file_path) final;
    const sf::Texture* get_texture(const types::Asset_id& id) const final;
    const sf::SoundBuffer* get_sound_buffer(const types::Asset_id& id) const final;

    const level::Level_interface& get_loaded_level_content() const final
    {
        return m_loaded_level;
    }

    const level::Render_level_interface& get_loaded_level_render() const final
    {
        return m_loaded_level;
    }

private:
    void create_color_textures();
    std::unordered_map<types::Asset_id, sf::Texture> m_textures;
    std::unordered_map<types::Asset_id, sf::SoundBuffer> m_sounds;
    std::unordered_map<std::string, types::Asset_id> m_asset_id_map;
    Asset_loader m_asset_loader;
    level::Level m_loaded_level;
};

}  // namespace assets