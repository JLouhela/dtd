#include "entt/entt.hpp"
#include "renderer/sprite_renderer_interface.hpp"

namespace renderer
{
class Sprite_renderer_interface;
}

namespace game
{
namespace sys
{

void render_sprites(entt::registry& reg, renderer::Sprite_renderer_interface& renderer);

}  // namespace sys
}  // namespace game