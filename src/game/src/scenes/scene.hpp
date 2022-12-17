#pragma once

#include <entt/entt.hpp>

namespace renderer
{
class Renderer_interface;
}

namespace game
{
class Scene
{
public:
    virtual ~Scene() = default;
    Scene(entt::registry& registry, renderer::Renderer_interface& renderer);
    virtual void dispose();
    virtual void update(std::int32_t delta_time);

protected:
    entt::registry& m_registry;
    renderer::Renderer_interface& m_renderer;

private:
};
}  // namespace game