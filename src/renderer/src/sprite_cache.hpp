#pragma once

#include <optional>
#include <vector>

#include "SFML/Graphics/Sprite.hpp"
#include "assets/assets_interface.hpp"
#include "renderer/sprite_id.hpp"

namespace renderer
{

class Sprite_cache
{
public:
    Sprite_cache(const assets::Assets_interface& assets);
    std::optional<sf::Sprite> get(const Sprite_id& id);

private:
    struct Sprite_creation_data
    {
        Sprite_creation_data(Sprite_id id, const sf::Texture* texture, sf::IntRect sprite_rect)
            : id{std::move(id)}, texture{texture}, sprite_rect{std::move(sprite_rect)}
        {
        }
        Sprite_id id;
        const sf::Texture* texture;
        sf::IntRect sprite_rect;
    };

    void init_rectangles();
    void init_towers();
    void init_enemies();
    void init_projectiles();

    const assets::Assets_interface& m_assets;
    std::vector<Sprite_creation_data> m_sprites;
};

}  // namespace renderer
