#pragma once

#include <memory>

namespace events
{
class Event_handler_interface;
}
class Mouse_listener;
namespace input
{

class Input_handler_interface
{
public:
    virtual ~Input_handler_interface() = default;
    void register_mouse_listener(const Mouse_listener& listener);
    // TODO read config
};

std::unique_ptr<Input_handler_interface> make_input_handler(events::Event_handler_interface& event_handler);

}  // namespace input