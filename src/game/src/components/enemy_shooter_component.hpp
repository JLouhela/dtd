#pragma once

#include <cstdint>
#include <limits>

namespace game::comp
{

static constexpr std::uint32_t INVALID_TARGET_ID = std::numeric_limits<std::uint32_t>::max();

struct Enemy_shooter
{
    Enemy_shooter(float shooting_delay) : shooting_delay{shooting_delay}
    {
    }
    std::uint32_t target_id{INVALID_TARGET_ID};
    float shooting_delay{1.0f};
    float shooting_time{0.0f};
};

}  // namespace game::comp