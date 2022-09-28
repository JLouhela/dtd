#pragma once

#include "game/game_interface.hpp"
#include "system_manager.hpp"

namespace game
{

class Game : public Game_interface
{
public:
    Game();
    ~Game() final = default;

    void update(std::int32_t delta_time) final;

private:
    System_manager m_system_manager;
};

}  // namespace game