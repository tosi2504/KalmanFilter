#ifndef MAT3DD_H
#define MAT3DD_H

#include "vec3D.h"

struct mat3D {
   vec3D data[3];
   
   mat3D();
   mat3D(const vec3D & row1, const vec3D & row2, const vec3D & row3);

   vec3D operator[](unsigned int idx) const;
   vec3D & operator[](unsigned int idx);

   static vec3D matmul(const mat3D & mat, const vec3D & vec);
   mat3D transpose();
   static mat3D matmul(const mat3D & mat1, const mat3D & mat2);
   void print();

   static mat3D generateRot(const float phi, const vec3D & n_);
};

#endif
