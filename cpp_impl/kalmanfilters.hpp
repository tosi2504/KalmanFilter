#pragma once

#include <array>
#include "math3D.hpp"
#include "math2D.hpp"
#include <cmath>

using vec2D = std::array<double, 2>;
using mat2x2 = std::array<double, 4>;

struct kf_1dim_tl {
    vec2D X, X_pred;
    mat2x2 P, P_pred;
    vec2D K;

    kf_1dim_tl() = delete;
    kf_1dim_tl(double x_init, double v_init, double sigma_x, double sigma_v);

    void time_update(double dt, double acc, double sigma_acc);
    void measurement_update(double pos, double sigma_pos);
    void skip_measurement_update();
};

struct kf_1dim_rot {
    double phi, phi_pred;
    double p, p_pred;

    kf_1dim_rot() = delete;
    kf_1dim_rot(double phi_init, double p_init);

    void time_update(double dt, double vel_phi, double sigma_vel_phi);
    void measurement_update(double phi_measurement, double sigma_phi);
    void skip_measurement_update();
};

void transform3D_vec_and_std(double yaw, double pitch, double roll, double std_yaw
                            , const vec3D & vec, double std
                            , vec3D & vec_targed, mat3D & cov_target);



using mat6D = mat2D<mat3D>;
using vec6D = vec2D<vec3D>;

struct kf_3dim_tl {
    vec6D X, X_pred;
    mat6D P, P_pred;

    kf_3dim_tl() = delete;
    kf_3dim_tl(const vec6D & X_init, const mat6D & P_init): X(X_init), P(P_init) {}

    void time_update(double dt, const vec3D & acc, const mat3D & cov_acc);
    void measurement_update(const vec3D & pos, const mat3D & pos_cov);
    void skip_measurement_update();
};
