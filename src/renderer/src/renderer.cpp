#include "renderer.hpp"

using namespace renderer;

std::unique_ptr<Renderer_interface> make_renderer()
{
    return std::make_unique<Renderer>();
}