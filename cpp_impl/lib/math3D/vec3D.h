#ifndef VEC3D_H
#define VEC3D_H

// NOTE: This vector class is defined in a right handed coordinate system

struct vec3D {
   float x,y,z;

   vec3D() = default;
   vec3D(float x, float y, float z);
   float operator[](unsigned int index) const;
   float & operator[](unsigned int index);

   void print();

   static float dot(const vec3D & v1, const vec3D & v2);
   static vec3D cross(const vec3D & v1, const vec3D & v2);
   static vec3D add(const vec3D & v1, const vec3D & v2);
   static vec3D negative(const vec3D & v1);
   static vec3D subtract(const vec3D & v1, const vec3D & v2);
   static float length(const vec3D & v1);
   static vec3D normalise(const vec3D & v1);
};

#endif
