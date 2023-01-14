#include "sound_system.hpp"

#include "../components/sound_component.hpp"
#include "sound_player/sound_player_interface.hpp"

namespace game
{
namespace sys::Sound_system
{

void play_hit_sounds(sound::Sound_player_interface& sound_player, entt::registry& reg)
{
    const auto view = reg.view<comp::Sound>();
    const entt::registry& creg = reg;
    for (const entt::entity e : view)
    {
        const auto& sound = creg.get<comp::Sound>(e);
        sound_player.play_sound(sound.sound);
        reg.remove<comp::Sound>(e);
    }
}

}  // namespace sys::Sound_system
}  // namespace game