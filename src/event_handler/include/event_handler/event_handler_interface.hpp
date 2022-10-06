#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <memory>

#include "event_listener.hpp"

namespace events
{

class Event_handler_interface
{
public:
    virtual ~Event_handler_interface() = default;
    virtual void update() = 0;
    virtual void register_listener(sf::Event::EventType event, Event_listener listener) = 0;
};

std::unique_ptr<Event_handler_interface> make_event_handler(sf::Window& window);

}  // namespace events