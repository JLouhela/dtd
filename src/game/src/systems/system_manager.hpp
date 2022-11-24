#pragma once

#include "entt/entt.hpp"

namespace renderer
{
class Renderer_interface;
}

namespace game
{
class System_manager
{
public:
    System_manager(entt::registry& registry, renderer::Renderer_interface& renderer);
    void execute();

private:
    entt::registry& m_registry;
    renderer::Renderer_interface& m_renderer;
};
}  // namespace game