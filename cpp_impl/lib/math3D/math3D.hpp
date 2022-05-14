#pragma once

#include <cmath>
#include <stdexcept>
#include <iostream>

struct vec3D {
   double x,y,z;

   vec3D() = default;
   vec3D(double x, double y, double z);
   double operator[](unsigned int index) const;
   double & operator[](unsigned int index);

   void print();

   static double dot(const vec3D & v1, const vec3D & v2);
   static vec3D cross(const vec3D & v1, const vec3D & v2);
   static vec3D add(const vec3D & v1, const vec3D & v2);
   static vec3D negative(const vec3D & v1);
   static vec3D subtract(const vec3D & v1, const vec3D & v2);
   static double length(const vec3D & v1);
   static vec3D normalise(const vec3D & v1);
   static vec3D gen_nr(double phi, double theta);
   static vec3D gen_nphi(double phi, double theta);
   static vec3D gen_ntheta(double phi, double theta);
   static vec3D scale(double a, const vec3D & v1);
};

vec3D operator*(double a, const vec3D & vec);
vec3D operator+(const vec3D & v1, const vec3D & v2);
vec3D operator-(const vec3D & v1, const vec3D & v2);

struct mat3D {
   vec3D data[3];

   mat3D();
   mat3D(const vec3D & row1, const vec3D & row2, const vec3D & row3);

   vec3D operator[](unsigned int idx) const;
   vec3D & operator[](unsigned int idx);

   static vec3D matmul(const mat3D & mat, const vec3D & vec);
   mat3D transpose() const;
   static mat3D matmul(const mat3D & mat1, const mat3D & mat2);
   double det() const;
   mat3D inv() const;
   void print() const;

   static mat3D generateRot(const double phi, const vec3D & n_);
   static mat3D generate_by_columns(const vec3D & col1, const vec3D & col2, const vec3D & col3);
   static mat3D identity();
};

mat3D operator*(const mat3D & mat1, const mat3D & mat2);
mat3D operator*(double scale, const mat3D & mat);
vec3D operator*(const mat3D & mat, const vec3D & vec);


mat3D operator+(const mat3D & mat1, const mat3D & mat2);
mat3D operator-(const mat3D & mat1, const mat3D & mat2);
