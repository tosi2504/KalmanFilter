#ifndef VEC3D_H
#define VEC3D_H

// NOTE: This vector class is defined in a right handed coordinate system

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
#endif
