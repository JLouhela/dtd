#include "sprite_renderer.hpp"

#include "loguru/loguru.hpp"

namespace renderer
{

Sprite_renderer::Sprite_renderer(std::shared_ptr<Sprite_cache> sprite_cache) : Subrenderer(std::move(sprite_cache))
{
}

void Sprite_renderer::render_sprite(const Sprite_id& sprite_id, const Screen_coord& screen_coord)
{
    auto sprite = m_sprite_cache->get(sprite_id);
    if (sprite.getTexture() == nullptr)
    {
        LOG_F(WARNING, "Could not find sprite for id %d", static_cast<int>(sprite_id));
        return;
    }
    sprite.setPosition({static_cast<float>(screen_coord.x), static_cast<float>(screen_coord.y)});
    draw(sprite);
}

}  // namespace renderer
