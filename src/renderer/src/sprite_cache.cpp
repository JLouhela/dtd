#include "sprite_cache.hpp"

#include <algorithm>

#include "loguru/loguru.hpp"

namespace renderer
{

Sprite_cache::Sprite_cache(const assets::Assets_interface& assets) : m_assets{assets}
{
    init_rectangles();
    init_towers();
}

sf::Sprite Sprite_cache::get(const Sprite_id& id)
{
    auto it = std::find_if(std::begin(m_sprites), std::end(m_sprites),
                           [&id](const auto& CachedSprite) { return CachedSprite.id == id; });
    if (it == m_sprites.end())
    {
        LOG_F(ERROR, "Could not find sprite %d", static_cast<int>(id));
        static const sf::Sprite invalid_sprite;
        return invalid_sprite;
    }
    return sf::Sprite{*it->texture, it->sprite_rect};
}

void Sprite_cache::init_rectangles()
{
    const sf::Texture* black_tex = m_assets.get_texture("texture_black");
    const sf::IntRect sprite_rect = {{0, 0}, {32, 32}};
    if (black_tex)
    {
        m_sprites.emplace_back(Sprite_id::Rectangle_black, black_tex, sprite_rect);
    }
    const sf::Texture* red_tex = m_assets.get_texture("texture_red");
    if (red_tex)
    {
        m_sprites.emplace_back(Sprite_id::Rectangle_red, red_tex, sprite_rect);
    }
    const sf::Texture* green_tex = m_assets.get_texture("texture_green");
    if (green_tex)
    {
        m_sprites.emplace_back(Sprite_id::Rectangle_green, green_tex, sprite_rect);
    }
}

void Sprite_cache::init_towers()
{
    LOG_F(WARNING, "Tower sprite initialization NOT implemented!");
    auto* tower_tex = m_assets.get_texture("td_tilesheet");
    // TODO load stuff
}

}  // namespace renderer
