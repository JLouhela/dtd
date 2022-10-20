#pragma once

#include "game/game_interface.hpp"
#include "renderer/renderer_interface.hpp"
#include "scenes/scene_manager.hpp"
#include "system_manager.hpp"

namespace game
{

class Game : public Game_interface
{
public:
    Game(renderer::Renderer_interface& renderer_interface);
    ~Game() final = default;

    void update(std::int32_t delta_time) final;

private:
    renderer::Renderer_interface& m_renderer;
    System_manager m_system_manager;
    Scene_manager m_scene_manager;
};

}  // namespace game