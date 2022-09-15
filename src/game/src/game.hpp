#pragma once

#include "game/game_interface.hpp"

namespace game
{

class Game : public Game_interface
{
public:
    Game();
    ~Game() final = default;

    void update(std::int32_t delta_time) final;

private:
};

}  // namespace game