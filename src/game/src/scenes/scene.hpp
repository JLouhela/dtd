#pragma once

#include <entt/entt.hpp>

namespace game
{
class Scene
{
public:
    virtual ~Scene() = default;
    Scene(entt::registry& registry);
    virtual void dispose();

protected:
    entt::registry& get_registry()
    {
        return m_registry;
    }

private:
    entt::registry& m_registry;
};
}  // namespace game