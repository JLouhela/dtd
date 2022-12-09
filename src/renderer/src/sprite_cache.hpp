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
    sf::Sprite* get(const Sprite_id& id);

private:
    struct CachedSprite
    {
        CachedSprite(Sprite_id id, sf::Sprite sprite) : id{std::move(id)}, sprite{std::move(sprite)}
        {
        }
        Sprite_id id;
        sf::Sprite sprite;
    };

    void init_rectangles();
    void init_towers();

    const assets::Assets_interface& m_assets;
    std::vector<CachedSprite> m_sprites;
};

}  // namespace renderer
