#include "entt/entt.hpp"

namespace renderer
{
class Hud_renderer_interface;
class Sprite_renderer_interface;
}  // namespace renderer

namespace game
{
namespace sys
{

void render_sprites(entt::registry& reg, renderer::Sprite_renderer_interface& renderer);
void render_hud(renderer::Hud_renderer_interface& renderer);

}  // namespace sys
}  // namespace game