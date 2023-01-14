#include "sound_player/sound_id.hpp"

#include "loguru/loguru.hpp"

namespace sound
{
Sound_id get_hit_sound(const types::Projectile_type& projectile_type)
{
    const auto it = HIT_SOUNDS.find(projectile_type);
    if (it != HIT_SOUNDS.end())
    {
        return it->second;
    }
    LOG_F(WARNING, "Hit sound with id %s does not exist / mapping missing!", static_cast<int>(projectile_type));
    return Sound_id::Silent;
}
}  // namespace sound