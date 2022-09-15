#pragma once

#include <cstdint>
#include <memory>

namespace game
{

class Game_interface
{
public:
    virtual ~Game_interface() = default;

    virtual void update(std::int32_t delta_time) = 0;
};

std::unique_ptr<Game_interface> make_game();

}  // namespace game
