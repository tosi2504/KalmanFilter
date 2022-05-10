#include "vec3D.h"
#include <cmath>
#include <stdexcept>

#include <iostream>

vec3D::vec3D(double x_, double y_, double z_) {
   x = x_; y = y_; z = z_;
}

double vec3D::operator[](unsigned int index) const {
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

double & vec3D::operator[](unsigned int index) {
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

double vec3D::dot(const vec3D & v1, const vec3D & v2) {
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

double vec3D::length(const vec3D & v1) {
   return std::sqrt(v1.x*v1.x + v1.y*v1.y + v1.z*v1.z);
}

vec3D vec3D::normalise(const vec3D & v1) {
   vec3D result = v1;
   double length = vec3D::length(v1);
   result.x /= length;
   result.y /= length;
   result.z /= length;
   return result;
}

vec3D vec3D::gen_nr(double phi, double theta) {
    return vec3D(std::sin(theta)*std::cos(phi), std::sin(theta)*std::sin(phi), std::cos(theta));
}

vec3D vec3D::gen_nphi(double phi, double theta) {
    return vec3D(-std::sin(phi), std::cos(theta), 0);
}
vec3D vec3D::gen_ntheta(double phi, double theta) {
    return vec3D(std::cos(theta)*std::cos(phi), std::cos(theta)*std::sin(phi), -std::sin(theta));
}
vec3D vec3D::scale(double a) {
    return vec3D(x*a, y*a, z*a);
}
