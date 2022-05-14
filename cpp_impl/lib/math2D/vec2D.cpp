#include "math2D.hpp"

template <typename T>
vec2D_T<T> vec2D<T>::T() {
    return vec2D_T<T>(x, y);
}

template <typename T>
vec2D<T> vec2D_T<T>::T() {
    return vec2D<T>(x, y);
}
