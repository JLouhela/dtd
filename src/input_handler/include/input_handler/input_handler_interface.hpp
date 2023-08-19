#pragma once

#include <memory>

namespace events
{
class Event_handler_interface;
}
namespace input
{

class Mouse_listener;
class Input_handler_interface
{
public:
    virtual ~Input_handler_interface() = default;
    virtual void register_mouse_listener(const Mouse_listener& listener) = 0;
    virtual void reset_listeners() = 0;

    // TODO read config
};

std::unique_ptr<Input_handler_interface> make_input_handler(events::Event_handler_interface& event_handler);

}  // namespace input