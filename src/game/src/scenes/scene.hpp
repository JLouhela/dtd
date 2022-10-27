#pragma once

namespace game
{
class Scene
{
public:
    virtual ~Scene() = default;
    virtual void dispose();
};
}  // namespace game