#include "sprite_renderer.hpp"

#include "loguru/loguru.hpp"
#include "window_size.hpp"

namespace renderer
{

Sprite_renderer::Sprite_renderer(const assets::Assets_interface& assets) : m_sprite_cache{assets}
{
    const auto ret = m_render_texture.create(constants::WINDOW_SIZE);
    if (!ret)
    {
        LOG_F(ERROR, "Failed to create render texture for debug renderer");
    }
}

void Sprite_renderer::render_sprite(const Sprite_id& sprite_id, const Screen_coord& screen_coord)
{
    auto* sprite = m_sprite_cache.get(sprite_id);
    if (!sprite)
    {
        LOG_F(WARNING, "Could not find sprite for id %d", static_cast<int>(sprite_id));
        return;
    }
    sprite->setPosition({static_cast<float>(screen_coord.x), static_cast<float>(screen_coord.y)});
    m_render_texture.draw(*sprite, m_renderStates);
}

void Sprite_renderer::clear()
{
    m_render_texture.clear(sf::Color::Transparent);
}

void Sprite_renderer::render()
{
    m_render_texture.display();
}

}  // namespace renderer
