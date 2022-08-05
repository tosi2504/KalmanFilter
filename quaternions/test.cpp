#include <iostream>

#include "quaternion.hpp"


int main () {
    Qtrn q = Qtrn::makeRotAboutUnitVec(123.123, {1,0,0});
    Qtrn q_bar = q.conj();
    Qtrn x = Qtrn::makeSpatialVec(0,0,1);
    Qtrn res = q * x * q_bar;
    std::cout << res.toString() << std::endl;
}
