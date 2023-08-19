#include "input_handler/input_handler_interface.hpp"

namespace input
{
class Input_handler : public Input_handler_interface
{
public:
    explicit Input_handler(events::Event_handler_interface& event_handler);

    void register_mouse_listener(const Mouse_listener& listener) override;
    void reset_listeners() override;

private:
    events::Event_handler_interface& m_event_handler;
};
}  // namespace input
