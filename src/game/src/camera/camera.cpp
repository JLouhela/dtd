#include "camera.hpp"

#include <cmath>

#include "loguru/loguru.hpp"

namespace game
{

Camera::Camera(std::uint8_t tile_size) : m_tile_size{tile_size}
{
}

math::Int_vector Camera::get_world_position(const math::Int_vector& screen_position)
{
    LOG_F(ERROR, "Camera::get_world_position() not implemented!");
    return {0, 0};
}

math::Int_vector Camera::get_screen_position(const math::Int_vector& world_position)
{
    LOG_F(ERROR, "Camera::get_world_position() not implemented!");
    return {0, 0};
}

math::Int_vector Camera::get_tile_coordinate(const math::Int_vector& world_position)
{
    return {m_position.x + world_position.x / m_tile_size, world_position.y / m_tile_size};
}

}  // namespace game