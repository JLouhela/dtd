#pragma once

#include <memory>

namespace renderer
{

class Renderer_interface
{
public:
    virtual ~Renderer_interface() = default;
    // TODO get window -> whatever maincpp needs now
};

std::unique_ptr<Renderer_interface> make_renderer();

}  // namespace renderer