#pragma once
#include "entt/entt.hpp"

namespace sound
{
class Sound_player_interface;
}

namespace game
{
namespace sys::Sound_system
{

void play_hit_sounds(sound::Sound_player_interface& sound_player, entt::registry& reg);

}  // namespace sys::Sound_system
}  // namespace game