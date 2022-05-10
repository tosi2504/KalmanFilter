#include "mat3D.h"

#include <iostream>
#include <cmath>

mat3D::mat3D() {
   data[0] = vec3D(0,0,0);
   data[1] = vec3D(0,0,0);
   data[2] = vec3D(0,0,0);
}

mat3D::mat3D(const vec3D & row1, const vec3D & row2, const vec3D & row3) {
   data[0] = row1;
   data[1] = row2;
   data[2] = row3;
}

vec3D mat3D::operator[](unsigned int idx) const {
   return data[idx];
}

vec3D & mat3D::operator[](unsigned int idx) {
   return data[idx];
}

vec3D mat3D::matmul(const mat3D & mat, const vec3D & vec) {
   vec3D res = {0,0,0};
   for (unsigned int i = 0; i < 3; i++) {
      res[i] = vec3D::dot(mat.data[i], vec);
   }
   return res;
}

mat3D mat3D::transpose() {
   mat3D res;
   for (unsigned int i = 0; i < 3; i++) {
      for (unsigned int j = 0; j < 3; j++) {
         res.data[i][j] = data[j][i];
      }
   }
   return res;
}

mat3D mat3D::matmul(const mat3D & mat1, const mat3D & mat2) {
   mat3D res;
   for (unsigned int i = 0; i < 3; i++) {
      for (unsigned int j = 0; j < 3; j++) {
         res.data[i][j] = 0;
         for (unsigned int c = 0; c < 3; c++) {
            res.data[i][j] += mat1.data[i][c] * mat2.data[c][j];
         }
      }
   }
   return res;
}

void mat3D::print() {
   for (unsigned int i = 0; i < 3; i++) {
      for (unsigned int j = 0; j < 3; j++) {
         std::cout << data[i][j] << " ";
      }
      std::cout << std::endl;
   }
}

mat3D mat3D::generateRot(const double phi, const vec3D & n_) {
   vec3D n = vec3D::normalise(n_);
   double cos = std::cos(phi);
   double sin = std::sin(phi);
   mat3D res;
   res.data[0][0] = cos + n.x*n.x * (1 - cos);
   res.data[0][1] = n.x*n.y * (1 - cos) - n.z*sin;
   res.data[0][2] = n.x*n.z * (1 - cos) + n.y*sin;
   res.data[1][0] = n.y*n.x * (1 - cos) + n.z*sin;
   res.data[1][1] = cos + n.y*n.y * (1 - cos);
   res.data[1][2] = n.y*n.z * (1 - cos) - n.x*sin;
   res.data[2][0] = n.z*n.x * (1 - cos) - n.y*sin;
   res.data[2][1] = n.z*n.y * (1 - cos) + n.x*sin;
   res.data[2][2] = cos + n.z*n.z * (1 - cos);
   return res;
}

mat3D mat3D::generate_by_columns(const vec3D & col1, const vec3D & col2, const vec3D & col3) {
    result = mat3D(col1, col2, col3);
    return result.transpose();
}
