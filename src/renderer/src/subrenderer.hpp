#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <memory>

#include "assets/assets_interface.hpp"
#include "sprite_cache.hpp"

namespace renderer
{

class Subrenderer
{
public:
    explicit Subrenderer(std::shared_ptr<Sprite_cache> sprite_cache);
    virtual ~Subrenderer() = default;
    sf::RenderTexture& get_render_texture()
    {
        return m_render_texture;
    }

    void clear();
    void render();

protected:
    void draw(const sf::Drawable& drawable);
    std::shared_ptr<Sprite_cache> m_sprite_cache;

private:
    sf::RenderStates m_renderStates{sf::RenderStates::Default};
    sf::RenderTexture m_render_texture;
};

}  // namespace renderer