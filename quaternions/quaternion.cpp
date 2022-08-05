#include "quaternion.hpp"
#include <cmath>


Qtrn Qtrn::makeSpatialVec(double x, double y, double z) {
    return Qtrn(0, x, y, z);
}

Qtrn Qtrn::makeSpatialVec(const std::array<double,3> & vec) {
    return Qtrn(0, vec[0], vec[1], vec[2]);
}

Qtrn Qtrn::makeRotAboutUnitVec(double theta, const std::array<double,3> & unitVec) {
    double s = std::sin(theta/2);
    return Qtrn(std::cos(theta/2), s*unitVec[0], s*unitVec[1], s*unitVec[2]);
}

Qtrn Qtrn::makeRotAboutVec(double theta, const std::array<double,3> & vec) {
    double norm = std::sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
    double s = std::sin(theta/2);
    return Qtrn(std::cos(theta/2), s*vec[0]/norm, s*vec[1]/norm, s*vec[2]/norm);
}

Qtrn Qtrn::conj() {
    return Qtrn(vals[0], -vals[1], -vals[2], -vals[3]);
}


std::string Qtrn::toString() {
    std::stringstream result;
    result << "r: " << vals[0] << "; ";
    result << "i: " << vals[1] << "; ";
    result << "j: " << vals[2] << "; ";
    result << "k: " << vals[3] << std::endl;
    return result.str();
}

Qtrn operator*(const Qtrn & x, const Qtrn & y) {
    Qtrn result;
    result[0] = x[0]*y[0] - x[1]*y[1] - x[2]*y[2] - x[3]*y[3];
    result[1] = x[0]*y[1] + x[1]*y[0] + x[2]*y[3] - x[3]*y[2];
    result[2] = x[0]*y[2] - x[1]*y[3] + x[2]*y[0] + x[3]*y[1];
    result[3] = x[0]*y[3] + x[1]*y[2] - x[2]*y[1] + x[3]*y[0];
    return result;
}
