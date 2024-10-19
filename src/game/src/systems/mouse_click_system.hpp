#pragma once

#include "entt/entt.hpp"

namespace game
{

class Camera;
namespace sys::Mouse_click_system
{

void process_mouse_click(entt::registry& reg, const Camera& camera);

}  // namespace sys::Mouse_click_system
}  // namespace game