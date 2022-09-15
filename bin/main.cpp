#include <SFML/Graphics.hpp>

int main()
{
    // TODO move to renderer
    sf::RenderWindow window(sf::VideoMode(sf::Vector2(200u, 200u), 32u), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        // TODO move to game_loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}