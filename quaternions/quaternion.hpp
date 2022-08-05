#include <array>
#include <string>
#include <sstream>



struct Qtrn {
    std::array<double,4> vals;

    // constructors
    Qtrn(): vals({0,0,0,0}) {}
    Qtrn(double r, double i, double j, double k): 
        vals({r,i,j,k}) {}
    Qtrn(const std::array<double,4> & vals): vals(vals) {}
    
    // special quaternions
    static Qtrn makeSpatialVec(double x, double y, double z);
    static Qtrn makeSpatialVec(const std::array<double,3> & vec);
    static Qtrn makeRotAboutUnitVec(double theta, const std::array<double,3> & unitVec);
    static Qtrn makeRotAboutVec(double theta, const std::array<double,3> & vec);

    // mathematical operations
    Qtrn conj();

    // access operators
    const double & operator[](unsigned int idx) const { return vals[idx]; };
    double & operator[](unsigned int idx) { return vals[idx]; };
    std::string toString();
};


// mathematical operations
Qtrn operator*(const Qtrn & x, const Qtrn & y);
