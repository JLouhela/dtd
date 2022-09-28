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
    void render() final;
    bool has_window() final;
    void close_window() final;
    bool get_window_event(sf::Event& event) final;

private:
    sf::RenderWindow m_window;
};

}  // namespace renderer
