
#include "SFML/Graphics.hpp"

namespace renderer
{

class Sprite : public sf::Drawable, public sf::Transformable
{
public:
    Sprite(const sf::Texture& texture, sf::VertexArray vertices);

private:
    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
    sf::VertexArray m_vertices;
    const sf::Texture& m_texture;
};

}  // namespace renderer
