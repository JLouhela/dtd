
#include "input_handler.hpp"

#include "event_handler/event_handler_interface.hpp"
#include "input_handler/mouse_listener.hpp"
#include "loguru/loguru.hpp"

namespace input
{

Input_handler::Input_handler(events::Event_handler_interface& event_handler) : m_event_handler{event_handler}
{
    m_mouse_click_listener.name = "Input_mclick";
    m_mouse_click_listener.callback = [this](const sf::Event& event)
    {
        if (!m_mouse_listener)
        {
            return;
        }
        if (event.mouseButton.button == sf::Mouse::Button::Left)
        {
            m_mouse_listener->mouse_left_clicked(event.mouseButton.x, event.mouseButton.y);
        }
    };
    event_handler.register_listener(sf::Event::EventType::MouseButtonPressed, m_mouse_click_listener);
}

void Input_handler::register_mouse_listener(const Mouse_listener& listener)
{
    if (m_mouse_listener)
    {
        LOG_F(INFO, "Input handler: Mouse listener replaced");
    }
    m_mouse_listener = &listener;
}

void Input_handler::reset_listeners()
{
}

std::unique_ptr<Input_handler_interface> make_input_handler(events::Event_handler_interface& event_handler)
{
    return std::make_unique<Input_handler>(event_handler);
}
}  // namespace input
