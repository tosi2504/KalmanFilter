#include "kalmanfilters.hpp"

#define R_PRECISION 0.00001

void transform3D_vec_and_std(double yaw, double pitch, double roll, double std_yaw
                            , const vec3D & vec, double std
                            , vec3D & vec_targed, mat3D & cov_target)
{
    // prepare the transformation matrix
    vec3D z = vec3D(0,0,1);
    mat3D rot_yaw = mat3D::generateRot(yaw, z);
    vec3D x_yaw = rot_yaw * vec3D(1,0,0);
    mat3D rot_pitch = mat3D::generateRot(pitch, x_yaw);
    vec3D y_yaw_pitch = rot_pitch * rot_yaw * vec(0,1,0)
    mat3D rot_roll = mat3D::generateRot(roll, y_yaw_pitch);

    mat3D transformation = rot_roll * rot_pitch * rot_yaw;

    // calculate phi, theta and r of vec:
    double r = std::sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
    if (std::abs(r) < R_PRECISION) {
        theta = M_PI_2;
    } else {
        double theta = std::acos(vec.z/r);
    }
    double phi = std::atan2(vec.y, vec.x);

    // transform the desired vector
    vec3D transformed_nr = transformation * vec3D::get_nr(phi, theta);
    vec3D transformed_ntheta = transformation * vec3D::gen_ntheta(phi, theta);
    vec3D transformed_nphi = transformation * vec3D::gen_nphi(phi, theta);
    // write transformed vec into target
    vec3D vec_target = r * transformed_nr;


    // lets build the covariance matrix in the transformed angular basis
    double azimuthal_factor = vec3D::length(std::cross(vec, z));
    double var_vec = std*std;
    double var_yaw = std*var_vec + azimuthal_factor*azimuthal_factor*std_yaw*std_yaw;
    mat3D cov_angular_basis = mat3D(vec3D(var_vec,0,0), vec3D(0,var_vec,0), vec3D(0,0,var_yaw));
    // now lets transform the covariance matrix
    mat3D basis_change = mat3D::generate_by_columns(transformed_nr, transformed_ntheta, transformed_nphi);
    // write transformed and error propagated covariance matrix into target
    mat3D cov_target = basis_change * cov_angular_basis * (basis_change.transpose());
}
