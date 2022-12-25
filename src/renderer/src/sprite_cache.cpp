#include "sprite_cache.hpp"

#include <algorithm>

#include "loguru/loguru.hpp"

namespace renderer
{

Sprite_cache::Sprite_cache(const assets::Assets_interface& assets) : m_assets{assets}
{
    init_rectangles();
    init_towers();
    init_enemies();
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
    auto sprite = sf::Sprite{*it->texture, it->sprite_rect};
    sprite.setOrigin({static_cast<float>(it->sprite_rect.width / 2), static_cast<float>(it->sprite_rect.height / 2)});
    return sprite;
}

void Sprite_cache::init_rectangles()
{
    const sf::Texture* black_tex = m_assets.get_texture("texture_black");
    const sf::IntRect sprite_rect = {{0, 0}, {64, 64}};
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
void Sprite_cache::init_enemies()
{
    auto* enemy_tex = m_assets.get_texture("td_tilesheet");
    const sf::IntRect sprite_rect = {{960, 640}, {64, 64}};
    m_sprites.emplace_back(Sprite_id::Basic_enemy, enemy_tex, sprite_rect);
}

}  // namespace renderer
