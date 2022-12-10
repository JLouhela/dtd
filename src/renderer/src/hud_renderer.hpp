#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "renderer/hud_renderer_interface.hpp"
#include "sprite_cache.hpp"
#include "subrenderer.hpp"

namespace renderer
{

class Hud_renderer : public Hud_renderer_interface, public Subrenderer
{
public:
    Hud_renderer(std::shared_ptr<Sprite_cache> sprite_cache);
    ~Hud_renderer() = default;
    void render_buy_menu() final;
};

}  // namespace renderer
