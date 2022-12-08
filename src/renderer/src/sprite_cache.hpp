#include <vector>

#include "assets/assets_interface.hpp"
#include "renderer/sprite_id.hpp"
#include "sprite.hpp"

namespace renderer
{

class Sprite_cache
{
public:
    Sprite_cache(const assets::Assets_interface& assets);
    const Sprite* get(const Sprite_id& id);

private:
    struct CachedSprite
    {
        CachedSprite(Sprite_id id, Sprite sprite) : id{std::move(id)}, sprite{std::move(sprite)}
        {
        }
        Sprite_id id;
        Sprite sprite;
    };

    void init_rectangles();
    void init_towers();

    const assets::Assets_interface& m_assets;
    std::vector<CachedSprite> m_sprites;
};

}  // namespace renderer
