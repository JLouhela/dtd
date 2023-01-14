#pragma once

#include "sound_player/sound_id.hpp"

namespace game::comp
{

struct Sound
{
    sound::Sound_id sound{sound::Sound_id::Silent};
};

}  // namespace game::comp