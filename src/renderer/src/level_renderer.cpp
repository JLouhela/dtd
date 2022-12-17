#include "level_renderer.hpp"

#include "loguru/loguru.hpp"

namespace renderer
{

Level_renderer::Level_renderer(const assets::Assets_interface& assets) : Subrenderer(nullptr), m_assets{assets}
{
}

void Level_renderer::render_current_level()
{
    static bool report = true;
    if (report)
    {
        LOG_F(WARNING, "render level not implemented");
        report = false;
    }
}

}  // namespace renderer
