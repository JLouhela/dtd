#pragma once

namespace renderer
{
class Debug_renderer_interface;
}

namespace game
{
namespace sys::debug::Render_system
{

void render_grid(renderer::Debug_renderer_interface& renderer);

}  // namespace sys::debug::Render_system
}  // namespace game