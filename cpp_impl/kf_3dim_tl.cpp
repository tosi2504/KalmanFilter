#include "kalmanfilters.hpp"

void kf_3dim_tl::time_update(double dt, const vec3D & acc, const mat3D & cov_acc) {
    X_pred.x = X.x + dt*X.y + dt*dt*0.5*acc;
    X_pred.y = X.y + dt*acc;

    P_pred.a = P.a + dt*P.b + dt*P.c + dt*dt*P.d + dt*dt*dt*dt/4*cov_acc;
    P_pred.b = P.b + dt*P.d + dt*dt*dt/2*cov_acc;
    P_pred.c = P.c + dt*P.d + dt*dt*dt/2*cov_acc;
    P_pred.d = P.d + dt*dt*cov_acc;
}

void kf_3dim_tl::measurement_update(const vec3D & pos, const mat3D & pos_cov) {
    mat3D inv = (P_pred.a + pos_cov).inv();
    mat3D Kx = P_pred.a*inv;
    mat3D Ky = P_pred.c*inv;

    X.x = X_pred.x + Kx*(pos - X_pred.x);
    X.y = X_pred.y + Ky*(pos - X_pred.y);

    mat3D I = mat3D::identity();
    P.a = (I - Kx) * P_pred.a * (I - Kx) + Kx*pos_cov*Kx;
    P.b = (I - Kx) * (P_pred.b - P_pred.a * Ky) + Kx*pos_cov*Ky;
    P.c = (P_pred.c - P_pred.a * Ky) * (I - Kx) + Ky*pos_cov*Kx;
    P.d = Ky*(P_pred.a*Ky - P_pred.a) + P_pred.d - P_pred.c*Ky  + Ky*pos_cov*Ky;
 }

void kf_3dim_tl::skip_measurement_update() {
    X = X_pred;
    P = P_pred;
}
