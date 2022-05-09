#include "vec3D.h"
#include <cmath>
#include <stdexcept>

#include <iostream>

vec3D::vec3D(float x_, float y_, float z_) {
   x = x_; y = y_; z = z_;
}

float vec3D::operator[](unsigned int index) const {
   if (index == 0) {
      return x;
   }
   if (index == 1) {
      return y;
   }
   if (index == 2) {
      return z;
   }
   throw std::invalid_argument("Only indices 0, 1, 2!");
}

float & vec3D::operator[](unsigned int index) {
   if (index == 0) {
      return x;
   }
   if (index == 1) {
      return y;
   }
   if (index == 2) {
      return z;
   }
   throw std::invalid_argument("Only indices 0, 1, 2!");
}

void vec3D::print() {
   std::cout << x << std::endl;
   std::cout << y << std::endl;
   std::cout << z << std::endl;
}

float vec3D::dot(const vec3D & v1, const vec3D & v2) {
   return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

vec3D vec3D::cross(const vec3D & v1, const vec3D & v2) {
   vec3D result;
   result.x = v1.y*v2.z - v1.z*v2.y;
   result.y = v1.z*v2.x - v1.x*v2.z;
   result.z = v1.x*v2.y - v1.y*v2.x;
   return result;
}

vec3D vec3D::add(const vec3D & v1, const vec3D & v2) {
   vec3D result;
   result.x = v1.x + v2.x;
   result.y = v1.y + v2.y;
   result.z = v1.z + v2.z;
   return result;
}

vec3D vec3D::negative(const vec3D & v1) {
   vec3D result;
   result.x = -v1.x;
   result.y = -v1.y;
   result.z = -v1.z;
   return result;
}

vec3D vec3D::subtract(const vec3D & v1, const vec3D & v2) {
   vec3D result;
   result.x = v1.x - v2.x;
   result.y = v1.y - v2.y;
   result.z = v1.z - v2.z;
   return result;
}

float vec3D::length(const vec3D & v1) {
   return std::sqrt(v1.x*v1.x + v1.y*v1.y + v1.z*v1.z);
}

vec3D vec3D::normalise(const vec3D & v1) {
   vec3D result = v1;
   float length = vec3D::length(v1);
   result.x /= length;
   result.y /= length;
   result.z /= length;
   return result;
}
