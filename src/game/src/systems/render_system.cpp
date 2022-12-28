#include "render_system.hpp"

#include "../components/position_component.hpp"
#include "../components/sprite_component.hpp"
#include "assets/render_level_interface.hpp"
#include "renderer/hud_renderer_interface.hpp"
#include "renderer/level_renderer_interface.hpp"
#include "renderer/sprite_renderer_interface.hpp"

namespace game
{
namespace sys::Render_system
{

void render_sprites(entt::registry& reg, renderer::Sprite_renderer_interface& renderer)
{
    const auto& creg = reg;
    const auto view = reg.view<comp::Position, comp::Sprite>();
    for (const entt::entity e : view)
    {
        const auto& pos = creg.get<comp::Position>(e);
        const auto& sprite = creg.get<comp::Sprite>(e);

        // TODO camera transform
        const auto screen_pos = renderer::Screen_coord{pos.x, pos.y};
        renderer.render_sprite(sprite.sprite, screen_pos);
    }
}

void render_hud(renderer::Hud_renderer_interface& renderer)
{
    renderer.render_buy_menu();
}
void render_level(renderer::Level_renderer_interface& renderer)
{
    renderer.render_current_level();
}

}  // namespace sys::Render_system
}  // namespace game