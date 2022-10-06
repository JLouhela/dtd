#include "game_loop.hpp"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "loguru/loguru.hpp"

namespace game_loop
{

Game_loop::Game_loop(game::Game_interface& game,
                     renderer::Renderer_interface& renderer,
                     events::Event_handler_interface& event_handler)
    : m_game{game}, m_renderer{renderer}, m_event_handler{event_handler}
{
}

void Game_loop::start()
{
    if (m_running)
    {
        return;
    }
    m_running = true;

    events::Event_listener listener{"game_loop_close", [this](const sf::Event& event)
                                    {
                                        LOG_F(INFO, "Window closed, shutdown game loop");
                                        m_renderer.close_window();
                                        stop();
                                    }};
    m_event_handler.register_listener(sf::Event::EventType::Closed, listener);

    LOG_F(INFO, "Starting game loop..");
    run();
}

void Game_loop::stop()
{
    m_running = false;
}

void Game_loop::run()
{
    sf::Clock delta_clock;
    while (m_running)
    {
        sf::Time dt = delta_clock.restart();
        m_event_handler.update();
        m_game.update(dt.asMilliseconds());
        m_renderer.render();
    }
    m_running = false;
}

std::unique_ptr<Game_loop_interface> make_game_loop(game::Game_interface& game,
                                                    renderer::Renderer_interface& renderer,
                                                    events::Event_handler_interface& event_handler)
{
    return std::make_unique<Game_loop>(game, renderer, event_handler);
}

}  // namespace game_loop