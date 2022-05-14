#pragma once

template <typename T>
struct vec2D {
    T x, y;

    vec2D() = default;
    vec2D(const T & x, const T & y): x(x), y(y) {}

};

template <typename T>
struct mat2D {
    T a, b, c, d;

    mat2D() = default;
    mat2D(const T & a, const T & b, const T & c, const T & d): a(a), b(b), c(c), d(d) {}

};


// operator overloading
