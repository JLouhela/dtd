#pragma once

#include "assets/assets_interface.hpp"
#include "game/game_interface.hpp"
#include "renderer/renderer_interface.hpp"
#include "scenes/scene_manager.hpp"

namespace game
{

class Game : public Game_interface
{
public:
    Game(renderer::Renderer_interface& renderer_interface, assets::Assets_interface& assets);
    ~Game() final = default;

    void update(std::int32_t delta_time) final;

private:
    entt::registry m_registry;
    renderer::Renderer_interface& m_renderer;
    assets::Assets_interface& m_assets;
    Scene_manager m_scene_manager;
};

}  // namespace game