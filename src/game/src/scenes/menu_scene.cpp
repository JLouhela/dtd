#include "menu_scene.hpp"

namespace game
{
Menu_scene::Menu_scene(entt::registry& registry,
                       renderer::Renderer_interface& renderer,
                       sound::Sound_player_interface& sound_player,
                       input::Input_handler_interface& input_handler)
    : Scene(registry, renderer, sound_player, input_handler)
{
}

}  // namespace game