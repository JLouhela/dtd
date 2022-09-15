#pragma once

#include "game/game_interface.hpp"

namespace game
{

class Game : public Game_interface
{
public:
    Game();
    ~Game() final = default;

private:
};

}  // namespace game