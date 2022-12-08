#include "sprite_cache.hpp"

#include <algorithm>

#include "loguru/loguru.hpp"

namespace
{
sf::VertexArray get_32_32_vertices()
{
    sf::VertexArray rect(sf::Triangles, 6);
    rect[0].position = sf::Vector2f(0.0f, 0.0f);
    rect[1].position = sf::Vector2f(32.0f, 0.0f);
    rect[2].position = sf::Vector2f(32.0f, 32.0f);
    rect[3].position = sf::Vector2f(32.0f, 32.0f);
    rect[4].position = sf::Vector2f(0.0, 32.0f);
    rect[5].position = sf::Vector2f(0.0f, 0.0f);

    rect[0].texCoords = sf::Vector2f(0.0f, 0.0f);
    rect[1].texCoords = sf::Vector2f(32.0f, 0.0f);
    rect[2].texCoords = sf::Vector2f(32.0f, 32.0f);
    rect[3].texCoords = sf::Vector2f(32.0f, 32.0f);
    rect[4].texCoords = sf::Vector2f(0.0, 32.0f);
    rect[5].texCoords = sf::Vector2f(0.0f, 0.0f);
    return rect;
}
}  // namespace

namespace renderer
{

Sprite_cache::Sprite_cache(const assets::Assets_interface& assets) : m_assets{assets}
{
    init_rectangles();
    init_towers();
}

const Sprite* Sprite_cache::get(const Sprite_id& id)
{
    auto it = std::find_if(std::cbegin(m_sprites), std::cend(m_sprites),
                           [&id](const auto& CachedSprite) { return CachedSprite.id == id; });
    if (it == m_sprites.end())
    {
        LOG_F(ERROR, "Could not find sprite %d", static_cast<int>(id));
        return nullptr;
    }
    return &(it->sprite);
}

void Sprite_cache::init_rectangles()
{
    const sf::Texture* black_tex = m_assets.get_texture("texture_black");
    if (black_tex)
    {
        m_sprites.emplace_back(Sprite_id::Rectangle_black, Sprite{*black_tex, get_32_32_vertices()});
    }
    const sf::Texture* red_tex = m_assets.get_texture("texture_red");
    if (red_tex)
    {
        m_sprites.emplace_back(Sprite_id::Rectangle_red, Sprite{*red_tex, get_32_32_vertices()});
    }
    const sf::Texture* green_tex = m_assets.get_texture("texture_green");
    if (green_tex)
    {
        m_sprites.emplace_back(Sprite_id::Rectangle_green, Sprite{*green_tex, get_32_32_vertices()});
    }
}

void Sprite_cache::init_towers()
{
    LOG_F(WARNING, "Tower sprite initialization NOT implemented!");
}

}  // namespace renderer
