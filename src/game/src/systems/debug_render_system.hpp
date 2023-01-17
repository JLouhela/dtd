#pragma once
#include "entt/entt.hpp"

namespace renderer
{
class Shape_renderer_interface;
}

namespace game
{
namespace sys::debug::Render_system
{

void render_grid(renderer::Shape_renderer_interface& renderer);
void render_shoot_radiuses(renderer::Shape_renderer_interface& renderer, entt::registry& reg);

}  // namespace sys::debug::Render_system
}  // namespace game