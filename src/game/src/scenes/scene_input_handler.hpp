#pragma once

#include <functional>

#include "input_handler/mouse_listener.hpp"

namespace input
{
class Input_handler_interface;
}

namespace game
{

using Mouse_left_handler = std::function<void(int x, int y)>;

class Scene_input_handler : public input::Mouse_listener
{
public:
    Scene_input_handler(input::Input_handler_interface& input_handler);

    void enable();
    void disable();

    void handle_mouse_left_click(Mouse_left_handler callback);

    // Mouse_listener
    void mouse_left_clicked(int x, int y) const final;

private:
    input::Input_handler_interface& m_input_handler;
    Mouse_left_handler m_mouse_left_callback;
};
}  // namespace game