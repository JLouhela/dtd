#pragma once

#include <cstdint>
#include <limits>

#include "types/entity_id.hpp"

namespace game::comp
{

struct Enemy_shooter
{
    Enemy_shooter(float shooting_delay) : shooting_delay{shooting_delay}
    {
    }
    types::Entity_id target_id{types::Invalid_entity_id};
    float shooting_delay{1.0f};
    bool enabled{true};
    float shooting_time{0.0f};
};

}  // namespace game::comp