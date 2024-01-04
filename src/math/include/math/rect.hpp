#pragma once

#include <cmath>
#include <cstdint>

#include "default_values.hpp"
#include "vector.hpp"

namespace math
{

template <typename T>
struct Rectangle
{
    Rectangle(T top_left_x, T top_left_y, T width, T height)
        : top_left{top_left_x, top_left_y}, width{width}, height{height}
    {
    }

    Vector<T> top_left{default_value<T>};
    T width{default_value<T>};
    T height{default_value<T>};

    bool contains(const Vector<T>& point) const
    {
        return point.x >= top_left.x && point.x <= (top_left.x + width) && point.y >= top_left.y &&
               point.y <= (top_left.y + height);
    }

    bool contains(Vector<T>&& point) const
    {
        return point.x >= top_left.x && point.x <= (top_left.x + width) && point.y >= top_left.y &&
               point.y <= (top_left.y + height);
    }
};

using Int_rect = Rectangle<std::int32_t>;
using UInt_rect = Rectangle<std::uint32_t>;
using Double_rect = Rectangle<double>;
using Float_rect = Rectangle<float>;

}  // namespace math