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
    Vector<T> top_left{default_value<T>};
    T width{default_value<T>};
    T height{default_value<T>};
};

using Int_rect = Rectangle<std::int32_t>;
using UInt_rect = Rectangle<std::uint32_t>;
using Double_rect = Rectangle<double>;
using Float_rect = Rectangle<float>;

}  // namespace math