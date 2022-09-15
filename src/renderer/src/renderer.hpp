#pragma once

#include "renderer/renderer_interface.hpp"

namespace renderer
{

class Renderer : public Renderer_interface
{
public:
    Renderer();
    ~Renderer() final = default;
};

}  // namespace renderer
