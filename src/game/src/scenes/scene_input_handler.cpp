#include "scene_input_handler.hpp"

#include "input_handler/input_handler_interface.hpp"
#include "loguru/loguru.hpp"

namespace game
{
Scene_input_handler::Scene_input_handler(input::Input_handler_interface& input_handler) : m_input_handler{input_handler}
{
    m_input_handler.register_mouse_listener(*this);
}

void Scene_input_handler::mouse_left_clicked(int x, int y) const
{
    LOG_F(INFO, "mouse click");
}
}  // namespace game