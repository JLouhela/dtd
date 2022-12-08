#include "sprite.hpp"

namespace renderer
{

Sprite::Sprite(const sf::Texture& texture, sf::VertexArray vertices)
    : m_texture{texture}, m_vertices{std::move(vertices)}
{
}

void Sprite::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
    // apply the entity's transform -- combine it with the one that was passed by the caller
    //  states.transform *= getTransform();  // getTransform() is defined by sf::Transformable

    // TODO how to work with sfml 3? renderstates is const now

    // apply the texture
    //  states.texture = &m_texture;

    // you may also override states.shader or states.blendMode if you want

    // draw the vertex array
    // target.draw(m_vertices, states);
}
}  // namespace renderer
