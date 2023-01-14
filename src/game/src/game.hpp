#pragma once
#include <entt/entt.hpp>

#include "game/game_interface.hpp"
#include "scenes/scene_manager.hpp"

namespace assets
{
class Assets_interface;
}
namespace renderer
{
class Renderer_interface;
}
namespace sound
{
class Sound_player_interface;
}

namespace game
{

class Game : public Game_interface
{
public:
    Game(renderer::Renderer_interface& renderer_interface,
         assets::Assets_interface& assets,
         sound::Sound_player_interface& sound_player);
    ~Game() final = default;

    void update(float delta_time) final;

private:
    entt::registry m_registry;
    renderer::Renderer_interface& m_renderer;
    assets::Assets_interface& m_assets;
    sound::Sound_player_interface& m_sound_player;
    Scene_manager m_scene_manager;
};

}  // namespace game