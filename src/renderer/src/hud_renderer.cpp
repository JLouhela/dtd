#include "hud_renderer.hpp"

#include "loguru/loguru.hpp"
#include "window_size.hpp"

namespace renderer
{

Hud_renderer::Hud_renderer(std::shared_ptr<Sprite_cache> sprite_cache) : Subrenderer(sprite_cache)
{
}

void Hud_renderer::render_buy_menu()
{
    auto sprite = m_sprite_cache->get(Sprite_id::Rectangle_black);
    if (sprite.getTexture() == nullptr)
    {
        LOG_F(WARNING, "Could not find sprite for Rectangle_black");
        return;
    }
    sprite.setPosition({400.0f, 200.0f});
    sprite.setScale({3.0f, 5.0f});
    draw(sprite);
}
}  // namespace renderer
