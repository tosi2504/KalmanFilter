#include "math2D.hpp"



template <typename T>
vec2D<T> mat2D<T>::matmul(const mat2D<T> & mat, const vec2D<T> & vec) {
    vec2D<T> result;
    result.x = mat.a * vec.x + mat.b * vec.y;
    result.y = mat.c * vec.x + mat.d * vec.y;
    return result;
}
