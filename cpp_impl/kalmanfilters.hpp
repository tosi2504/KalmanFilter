#pragma once

#include <array>

using vec2 = std::array<double, 2>;
using mat2x2 = std::array<double, 4>;

struct kf_1dim_tl {
    vec2 X, X_pred;
    mat2x2 P, P_pred;
    vec2 K;

    kf_1dim_tl() = delete;
    kf_1dim_tl(double x_init, double v_init, double sigma_x, double sigma_v);

    void time_update(double dt, double acc, double sigma_acc);
    void measurement_update(double pos, double sigma_pos);
    void skip_measurement_update();
};
