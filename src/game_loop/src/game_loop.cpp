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
    sf::Clock delta_clock;
    while (m_renderer.has_window() && m_running)
    {
        sf::Event event;
        // TODO create some central event handler
        while (m_renderer.get_window_event(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_renderer.close_window();
            }
        }
        sf::Time dt = delta_clock.restart();
        m_game.update(dt.asMilliseconds());
        m_renderer.render();
    }
    m_running = false;
}

std::unique_ptr<Game_loop_interface> make_game_loop(game::Game_interface& game, renderer::Renderer_interface& renderer)
{
    return std::make_unique<Game_loop>(game, renderer);
}

}  // namespace game_loop