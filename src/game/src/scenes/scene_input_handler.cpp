#include "scene_input_handler.hpp"

#include "input_handler/input_handler_interface.hpp"
#include "loguru/loguru.hpp"

namespace game
{
Scene_input_handler::Scene_input_handler(input::Input_handler_interface& input_handler) : m_input_handler{input_handler}
{
}

void Scene_input_handler::enable()
{
    m_input_handler.register_mouse_listener(*this);
}

void Scene_input_handler::disable()
{
    m_input_handler.reset_listeners();
}

void Scene_input_handler::mouse_left_clicked(int x, int y) const
{
    if (m_mouse_left_callback)
    {
        m_mouse_left_callback(x, y);
    }
}

void Scene_input_handler::handle_mouse_left_click(Mouse_left_handler callback)
{
    m_mouse_left_callback = callback;
}
}  // namespace game