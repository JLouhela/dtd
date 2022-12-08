#include "sprite_renderer.hpp"

#include "loguru/loguru.hpp"

namespace renderer
{

Sprite_renderer::Sprite_renderer(const assets::Assets_interface& assets) : m_sprite_cache{assets}
{
}
void Sprite_renderer::render_sprite(const Sprite_id& sprite_id, const Screen_coord& screen_coord)
{
    const auto& sprite = m_sprite_cache.get(sprite_id);
    static bool note = false;
    if (!note)
    {
        note = true;
        LOG_F(WARNING, "Render sprite not implemented");
    }
}

}  // namespace renderer
