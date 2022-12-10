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
    static bool note = true;
    if (note)
    {
        LOG_F(WARNING, "Hud renderer, render buy menu not implemented!");
        note = false;
    }
}
}  // namespace renderer
