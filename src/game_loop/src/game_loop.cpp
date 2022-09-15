#include "game_loop.hpp"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

namespace game_loop
{

Game_loop::Game_loop(game::Game_interface& game, renderer::Renderer_interface& renderer)
    : m_game{game}, m_renderer{renderer}
{
}

void Game_loop::start()
{
    if (m_running)
    {
        return;
    }
    m_running = true;
    run();
}

void Game_loop::stop()
{
    m_running = false;
}

void Game_loop::run()
{
    auto& window = m_renderer.get_window();
    while (window.isOpen() && m_running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // game.update();
        window.clear();
        // window.draw(shape);
        window.display();
    }
    m_running = false;
}

std::unique_ptr<Game_loop_interface> make_game_loop(game::Game_interface& game, renderer::Renderer_interface& renderer)
{
    return std::make_unique<Game_loop>(game, renderer);
}

}  // namespace game_loop