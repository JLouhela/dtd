#pragma once

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
    sf::Sprite get(const Sprite_id& id);

private:
    struct SpriteCreationData
    {
        SpriteCreationData(Sprite_id id, const sf::Texture* texture, sf::IntRect sprite_rect)
            : id{std::move(id)}, texture{texture}, sprite_rect{std::move(sprite_rect)}
        {
        }
        Sprite_id id;
        const sf::Texture* texture;
        sf::IntRect sprite_rect;
    };

    void init_rectangles();
    void init_towers();

    const assets::Assets_interface& m_assets;
    std::vector<SpriteCreationData> m_sprites;
};

}  // namespace renderer
