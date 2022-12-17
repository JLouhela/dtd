#pragma once

namespace assets
{
class Render_level_interface;
}

namespace renderer
{

class Level_renderer_interface
{
public:
    virtual ~Level_renderer_interface() = default;

    virtual void render_current_level() = 0;
};

}  // namespace renderer