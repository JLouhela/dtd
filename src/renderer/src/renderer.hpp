#pragma once

#include <SFML/Graphics.hpp>

#include "renderer/renderer_interface.hpp"

namespace renderer
{

class Renderer : public Renderer_interface
{
public:
    Renderer();
    ~Renderer() final = default;
    sf::RenderWindow& get_window() final;

private:
    sf::RenderWindow m_window;
};

}  // namespace renderer
