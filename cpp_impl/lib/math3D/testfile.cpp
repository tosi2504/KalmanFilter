#include "mat3D.h"
#include "vec3D.h"
#include <cmath>
#include <iostream>
#include <tuple>


std::tuple<vec3D, vec3D> calcShovelCorner(const vec3D & GS_l, const vec3D & GS_r //
                                          , float yaw, float pitch, float roll)
{
   vec3D ax_yaw = {0,0,1};
   mat3D rot_yaw = mat3D::generateRot(yaw, ax_yaw);
   vec3D ax_roll = mat3D::matmul(rot_yaw, vec3D(0,1,0));
   mat3D rot_roll = mat3D::generateRot(roll, ax_roll);
   vec3D ax_pitch = mat3D::matmul(rot_roll, mat3D::matmul(rot_yaw, vec3D(1,0,0)));
   mat3D rot_pitch = mat3D::generateRot(pitch, ax_pitch);

   vec3D GS_l_res = mat3D::matmul(rot_pitch, mat3D::matmul(rot_roll, mat3D::matmul(rot_yaw, GS_l)));
   vec3D GS_r_res = mat3D::matmul(rot_pitch, mat3D::matmul(rot_roll, mat3D::matmul(rot_yaw, GS_r)));

   return std::make_tuple(GS_l_res, GS_r_res);
}



int main () {
   vec3D GS_l = {-1,0,0};
   vec3D GS_r = {1,0,0};

   float yaw = M_PI/2; // -> {}
   float pitch = M_PI/4; // -> {0, 0.7 ,-0.7}
   float roll = M_PI/4; // -> {0, 0.7, -0.7}

   vec3D GS_l_tf, GS_r_tf;
   std::tie(GS_l_tf, GS_r_tf) = calcShovelCorner(GS_l, GS_r, yaw, pitch, roll);
   GS_l_tf.print(); // left
   GS_r_tf.print(); // right
}
