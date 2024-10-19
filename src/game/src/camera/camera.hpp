#pragma once

#include <cstdint>

#include "math/vector.hpp"

namespace game
{

class Camera
{
public:
    Camera(std::uint8_t tile_size);

    void set_viewport_size(const math::UInt_vector& size)
    {
        m_viewport_size = size;
    }

    math::UInt_vector get_viewport_size() const
    {
        return m_viewport_size;
    }

    void set_position(const math::Int_vector& pos)
    {
        m_position = pos;
    }

    math::Int_vector get_world_position(const math::Int_vector& screen_position);
    math::Int_vector get_screen_position(const math::Int_vector& world_position);
    math::Int_vector get_tile_coordinate(const math::Int_vector& world_position);

private:
    std::uint8_t m_tile_size{0};
    math::Int_vector m_position{0, 0};
    math::UInt_vector m_viewport_size{0, 0};
};

}  // namespace game
