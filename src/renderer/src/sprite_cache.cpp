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
    init_projectiles();
}

std::optional<sf::Sprite> Sprite_cache::get(const Sprite_id& id)
{
    auto it = std::find_if(std::begin(m_sprites), std::end(m_sprites),
                           [&id](const auto& CachedSprite) { return CachedSprite.id == id; });
    if (it == m_sprites.end())
    {
        LOG_F(ERROR, "Could not find sprite %d", static_cast<int>(id));
        return {};
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
    auto* tower_tex = m_assets.get_texture("td_tilesheet");
    const sf::IntRect basic_tower_rect = {{1216, 640}, {64, 64}};
    m_sprites.emplace_back(Sprite_id::Basic_tower, tower_tex, basic_tower_rect);
}

void Sprite_cache::init_enemies()
{
    auto* enemy_tex = m_assets.get_texture("td_tilesheet");
    const sf::IntRect basic_enemy_rect = {{960, 640}, {64, 64}};
    m_sprites.emplace_back(Sprite_id::Basic_enemy, enemy_tex, basic_enemy_rect);
}

void Sprite_cache::init_projectiles()
{
    auto* projectile_tex = m_assets.get_texture("td_tilesheet");
    const sf::IntRect basic_bullet_rect = {{1216, 704}, {64, 64}};
    m_sprites.emplace_back(Sprite_id::Basic_projectile, projectile_tex, basic_bullet_rect);

    const sf::IntRect basic_hit_rect_1 = {{1216, 768}, {64, 64}};
    m_sprites.emplace_back(Sprite_id::Basic_projectile_hit_1, projectile_tex, basic_hit_rect_1);

    const sf::IntRect basic_hit_rect_2 = {{1280, 768}, {64, 64}};
    m_sprites.emplace_back(Sprite_id::Basic_projectile_hit_2, projectile_tex, basic_hit_rect_2);
}

}  // namespace renderer
