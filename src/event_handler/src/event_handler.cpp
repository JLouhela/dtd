#include "event_handler.hpp"

#include "loguru/loguru.hpp"

namespace events
{

Event_handler::Event_handler(sf::Window& window) : m_window{window}
{
}

void Event_handler::register_listener(const sf::Event::EventType event, Event_listener listener)
{
    auto& listeners = m_listeners[event];
    const auto& existing_listener =
        std::find_if(listeners.begin(), listeners.end(),
                     [&name = listener.name](const Event_listener& listener) { return listener.name == name; });
    if (existing_listener != listeners.end())
    {
        LOG_F(WARNING, "Tried to register listener with same name twice! Rejected %s", listener.name.c_str());
        return;
    }
    LOG_F(INFO, "Registered listener: %s", listener.name.c_str());
    listeners.emplace_back(listener);
}

void Event_handler::update()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        const auto& listeners = m_listeners[event.type];
        for (const auto& listener : listeners)
        {
            listener.callback(event);
        }
    }
}

std::unique_ptr<Event_handler_interface> make_event_handler(sf::Window& window)
{
    return std::make_unique<Event_handler>(window);
}
}  // namespace events