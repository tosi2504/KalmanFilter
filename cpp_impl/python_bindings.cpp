#include <pybind11/pybind11.h>

namespace py = pybind11;

#include "kalmanfilters.hpp"

PYBIND11_MODULE(pykalman, m) {
    m.doc() = "cpp kalmanfilters exposed to python";
    py::class_<kf_1dim_tl>(m, "kf_1dim_tl")
        .def(py::init<double, double, double, double>())
        .def("time_update", &kf_1dim_tl::time_update)
        .def("measurement_update", &kf_1dim_tl::measurement_update)
        .def("skip_measurement_update", &kf_1dim_tl::skip_measurement_update);
}
