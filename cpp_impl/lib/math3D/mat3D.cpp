#include "math3D.hpp"


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

mat3D mat3D::transpose() const {
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

double mat3D::det() const {
    double pos = data[0][0]*data[1][1]*data[2][2] + data[0][1]*data[1][2]*data[2][0] + data[0][2]*data[1][0]*data[2][1];
    double neg = data[2][0]*data[1][1]*data[0][2] + data[2][1]*data[1][2]*data[0][0] + data[2][2]*data[1][0]*data[0][1];
    return pos - neg;
}


mat3D mat3D::inv() const {
    mat3D res;
    res[0][0] = data[1][1]*data[2][2] - data[1][2]*data[2][1];
    res[0][1] = data[0][2]*data[2][1] - data[0][1]*data[2][2];
    res[0][2] = data[0][1]*data[1][2] - data[0][2]*data[1][1];

    res[1][0] = data[1][2]*data[2][0] - data[1][0]*data[2][2];
    res[1][1] = data[0][0]*data[2][2] - data[0][2]*data[2][0];
    res[1][2] = data[0][2]*data[1][0] - data[0][0]*data[1][2];

    res[2][0] = data[1][0]*data[2][1] - data[1][1]*data[2][0];
    res[2][1] = data[0][1]*data[2][0] - data[0][0]*data[2][1];
    res[2][2] = data[0][0]*data[1][1] - data[0][1]*data[1][0];

    return 1/(this->det()) * res;
}


void mat3D::print() const {
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
    mat3D result = mat3D(col1, col2, col3);
    return result.transpose();
}

mat3D mat3D::identity() {
    mat3D result;
    for (int m = 0; m < 3; m++) {
        for (int n = 0; n < 3; n++) {
            if (m == n) result[m][n] = 1;
            else result[m][n] = 0;
        }
    }
}

mat3D operator*(const mat3D & mat1, const mat3D & mat2) {
    return mat3D::matmul(mat1, mat2);
}

mat3D operator*(double scale, const mat3D & mat) {
    mat3D result = mat;
    result.data[0] = scale*mat.data[0];
    result.data[1] = scale*mat.data[1];
    result.data[2] = scale*mat.data[2];
    return result;
}

vec3D operator*(const mat3D & mat, const vec3D & vec) {
    return mat3D::matmul(mat, vec);
}

mat3D operator+(const mat3D & mat1, const mat3D & mat2) {
    mat3D result;
    for (int m = 0; m < 3; m++) {
        for (int n = 0; n < 3; n++) {
            result[m][n] = mat1[m][n] + mat2[m][n];
        }
    }
    return result;
}

mat3D operator-(const mat3D & mat1, const mat3D & mat2) {
    mat3D result;
    for (int m = 0; m < 3; m++) {
        for (int n = 0; n < 3; n++) {
            result[m][n] = mat1[m][n] - mat2[m][n];
        }
    }
    return result;
}
