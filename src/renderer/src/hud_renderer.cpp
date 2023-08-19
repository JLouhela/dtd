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
    if (!sprite.has_value())
    {
        LOG_F(WARNING, "Could not find sprite for Rectangle_black");
        return;
    }
    // sprite.setOrigin({0.0f, 0.0f});
    sprite.value().setPosition({800.0f, 200.0f});
    sprite.value().setScale({5.0f, 10.0f});
    draw(sprite.value());
}
}  // namespace renderer
