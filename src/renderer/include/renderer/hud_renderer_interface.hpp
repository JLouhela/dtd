#pragma once

namespace renderer
{

class Hud_renderer_interface
{
public:
    virtual ~Hud_renderer_interface() = default;

    virtual void render_buy_menu() = 0;
};

}  // namespace renderer