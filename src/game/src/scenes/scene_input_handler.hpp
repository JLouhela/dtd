#pragma once

#include "input_handler/mouse_listener.hpp"

namespace input
{
class Input_handler_interface;
}

namespace game
{
class Scene_input_handler : public input::Mouse_listener
{
public:
    Scene_input_handler(input::Input_handler_interface& input_handler);

    // Mouse_listener
    void mouse_left_clicked(int x, int y) const final;

private:
    input::Input_handler_interface& m_input_handler;
};
}  // namespace game