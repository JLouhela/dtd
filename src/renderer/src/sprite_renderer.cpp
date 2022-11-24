#include "sprite_renderer.hpp"

#include "loguru/loguru.hpp"

namespace renderer
{
void Sprite_renderer::render_sprite(const Sprite_id& sprite_id, const Screen_coord& screen_coord)
{
    static bool note = false;
    if (!note)
    {
        note = true;
        LOG_F(WARNING, "Render sprite not implemented");
    }

    // TODO: sprite_id -> texture
    /*
    sf::Texture texture;
if (!texture.loadFromFile("image.png"))
{
    // error...
}
*/
}

}  // namespace renderer
