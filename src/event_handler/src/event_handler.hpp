#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "event_handler/event_handler_interface.hpp"

namespace events
{

class Event_handler : public Event_handler_interface
{
public:
    Event_handler(sf::Window& window);
    ~Event_handler() final = default;
    void update() final;
    void register_listener(sf::Event::EventType event, Event_listener listener) final;

private:
    std::unordered_map<sf::Event::EventType, std::vector<Event_listener>> m_listeners;
    sf::Window& m_window;
};

}  // namespace events
