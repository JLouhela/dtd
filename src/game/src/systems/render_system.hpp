#include "entt/entt.hpp"

namespace renderer
{
class Hud_renderer_interface;
class Sprite_renderer_interface;
class Level_renderer_interface;
}  // namespace renderer

namespace assets
{
class Render_level_interface;
}

namespace game
{
namespace sys::Render_system
{

void render_sprites(entt::registry& reg, renderer::Sprite_renderer_interface& renderer);
void render_hud(renderer::Hud_renderer_interface& renderer);
void render_level(renderer::Level_renderer_interface& renderer);

}  // namespace sys::Render_system
}  // namespace game