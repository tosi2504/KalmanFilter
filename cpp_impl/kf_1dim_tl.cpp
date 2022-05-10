#include "kalmanfilters.hpp"

kf_1dim_tl::kf_1dim_tl(double x_init, double v_init, double sigma_x, double sigma_v) {
    X[0] = x_init;
    X[1] = v_init;
    P[0] = sigma_x;
    P[3] = sigma_v;
}

void kf_1dim_tl::time_update(double dt, double acc, double sigma_acc) {
    double dt2 = dt*dt;
    X_pred[0] = X[0] + dt * X[1] + 0.5 * dt2 * acc;
    X_pred[1] = X[1] + dt * acc;

    double sigma2 = sigma_acc*sigma_acc;
    P_pred[0] = P[0] + dt*P[1] + dt*P[2] + dt2*P[3] + sigma2 * dt2*dt2 / 4.0f;
    P_pred[1] = P[1] + dt*P[3] + sigma2*dt*dt2/2.0f;
    P_pred[2] = P_pred[1];
    P_pred[3] = P[3] + sigma2*dt2;
}

void kf_1dim_tl::measurement_update(double pos, double sigma_pos) {
    K[0] = P_pred[0] / (P_pred[0] + sigma_pos);
    K[1] = P_pred[2] / (P_pred[0] + sigma_pos);

    X[0] = X_pred[0] + K[0] * (pos - X_pred[0]);
    X[1] = X_pred[1] + K[1] * (pos - X_pred[0]);

    P[0] = P_pred[0]*(1 - K[0])*(1 - K[0]) + sigma_pos * K[0] * K[0];
    P[1] = (1 - K[0]) * (P_pred[1] - P_pred[0]*K[1]) + sigma_pos * K[0] * K[1];
    P[2] = P[1];
    P[3] = K[1]*(K[1]*P_pred[0] - P_pred[1]) + P_pred[3] - K[1]*P_pred[2] + sigma_pos * K[1] * K[1];
}

void kf_1dim_tl::skip_measurement_update() {
    X = X_pred;
    P = P_pred;
}
