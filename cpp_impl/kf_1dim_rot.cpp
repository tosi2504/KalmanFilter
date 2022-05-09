#include "kalmanfilters.hpp"

kf_1dim_rot::kf_1dim_rot(double phi_init, double p_init) {
    phi = phi_init;
    p = p_init;
}
void kf_1dim_rot::time_update(double dt, double vel_phi, double sigma_vel_phi) {
    phi_pred = phi + dt * vel_phi;
    // G = dt -> Q = sigma2 * G G.T = dt*dt*sigma*sigma
    p_pred = p + dt*dt*sigma_vel_phi*sigma_vel_phi;
}
void kf_1dim_rot::measurement_update(double phi_measurement, double sigma_phi) {
    double k = p_pred / (p_pred + sigma_phi * sigma_phi);
    phi = phi_pred + k * (phi_measurement - phi_pred);
    p = (1 - k)*p_pred;
}
void kf_1dim_rot::skip_measurement_update() {
    phi = phi_pred;
    p = p_pred;
}
