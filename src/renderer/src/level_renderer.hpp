#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "renderer/level_renderer_interface.hpp"
#include "sprite_cache.hpp"
#include "subrenderer.hpp"

namespace assets
{
class Assets_interface;
}

namespace renderer
{

class Level_renderer : public Level_renderer_interface, public Subrenderer
{
public:
    explicit Level_renderer(const assets::Assets_interface& assets);
    void render_current_level() final;
    void init_current_Level() final;

private:
    std::vector<sf::VertexArray> m_vertices;
    const assets::Assets_interface& m_assets;
};

}  // namespace renderer
