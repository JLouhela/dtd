#pragma once

#include <cstdint>

class Game_interface
{
public:
    virtual ~Game_interface() = default;

    virtual void update(std::int32_t delta_time) = 0;
};
