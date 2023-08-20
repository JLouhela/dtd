#include "subrenderer.hpp"

#include "loguru/loguru.hpp"
#include "window_size.hpp"

namespace renderer
{

Subrenderer::Subrenderer(std::shared_ptr<Sprite_cache> sprite_cache) : m_sprite_cache{std::move(sprite_cache)}
{
    const auto ret = m_render_texture.create(constants::WINDOW_SIZE);
    if (!ret)
    {
        LOG_F(ERROR, "Failed to create render texture for debug renderer");
    }
}

void Subrenderer::clear()
{
    m_render_texture.clear(sf::Color::Transparent);
}

void Subrenderer::render()
{
    m_render_texture.display();
}

void Subrenderer::draw(const sf::Drawable& drawable)
{
    m_render_texture.draw(drawable, m_renderStates);
}

}  // namespace renderer