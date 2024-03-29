#include "debug_render_system.hpp"

#include "../components/circle_radius_component.hpp"
#include "../components/position_component.hpp"
#include "constants.hpp"
#include "renderer/shape_renderer_interface.hpp"

namespace game
{
namespace sys::debug::Render_system
{
void render_grid(renderer::Shape_renderer_interface& renderer)
{
    renderer.draw_grid(constants::TILE_SIZE);
}

void render_shoot_radiuses(renderer::Shape_renderer_interface& renderer, entt::registry& reg)
{
    const auto view = reg.view<comp::Circle_radius, comp::Position>();
    const entt::registry& creg = reg;
    for (const entt::entity e : view)
    {
        const auto& radius = creg.get<comp::Circle_radius>(e);
        const auto& pos = creg.get<comp::Position>(e);
        renderer.draw_circle({static_cast<std::int32_t>(pos.x), static_cast<std::int32_t>(pos.y)}, radius.radius);
    }
}

}  // namespace sys::debug::Render_system
}  // namespace game