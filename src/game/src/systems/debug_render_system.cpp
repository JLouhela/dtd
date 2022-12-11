#include "debug_render_system.hpp"

#include "constants.hpp"
#include "renderer/debug_renderer_interface.hpp"

namespace game
{
namespace sys::debug
{
void render_grid(renderer::Debug_renderer_interface& renderer)
{
    renderer.draw_grid(constants::TILE_SIZE);
}

}  // namespace sys::debug
}  // namespace game