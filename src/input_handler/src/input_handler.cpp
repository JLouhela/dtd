
#include "input_handler.hpp"

#include "event_handler/event_handler_interface.hpp"
#include "input_handler/mouse_listener.hpp"
#include "loguru/loguru.hpp"

namespace input
{

Input_handler::Input_handler(events::Event_handler_interface& event_handler) : m_event_handler{event_handler}
{
}

void register_mouse_listener(const Mouse_listener& listener)
{
    LOG_F(WARNING, "Register mouse listener - not implemented yet!");
}
std::unique_ptr<Input_handler_interface> make_input_handler(events::Event_handler_interface& event_handler)
{
    return std::make_unique<Input_handler>(event_handler);
}
}  // namespace input
