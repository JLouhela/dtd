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

    // TODO move to input_handler
    events::Event_listener loop_close_listener{"game_loop_close", [this](const sf::Event&)
                                               {
                                                   LOG_F(INFO, "Window closed, shutdown game loop");
                                                   m_renderer.close_window();
                                                   stop();
                                               }};

    events::Event_listener speed_button{"double_speed_button", [this](const sf::Event& event)
                                        {
                                            if (event.key.code != sf::Keyboard::Key::Space)
                                            {
                                                return;
                                            }
                                            if (event.type == sf::Event::KeyPressed)
                                            {
                                                m_fast_forward = true;
                                            }
                                            else if (event.type == sf::Event::KeyReleased)
                                            {
                                                m_fast_forward = false;
                                            }
                                        }};

    m_event_handler.register_listener(sf::Event::EventType::Closed, loop_close_listener);
    m_event_handler.register_listener(sf::Event::EventType::KeyPressed, speed_button);
    m_event_handler.register_listener(sf::Event::EventType::KeyReleased, speed_button);

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
        const auto delta_time = dt.asSeconds() * (m_fast_forward ? 6.f : 1.f);
        m_game.update(delta_time);
        m_renderer.render();
        m_renderer.clear();
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