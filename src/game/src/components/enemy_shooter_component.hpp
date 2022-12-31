#pragma once

#include <cstdint>

namespace game::comp
{

struct Enemy_shooter
{
    Enemy_shooter(float shooting_delay) : shooting_delay{shooting_delay}
    {
    }
    std::int32_t target_id{-1};
    float shooting_delay{1.0f};
    float shooting_time{0.0f};
};

}  // namespace game::comp