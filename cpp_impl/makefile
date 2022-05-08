CXX = clang++
INC_PYBIND = -I ~/.local/lib/python3.8/site-packages/pybind11/include
INC_PYCONFIG = -I /usr/include/python3.8

all: kf_1dim_tl.o python_bindings.cpp
	$(CXX) -Wall -shared -fPIC $(INC_PYBIND) $(INC_PYCONFIG) kf_1dim_tl.o python_bindings.cpp -o pykalman.so

kf_1dim_tl.o: kalmanfilters.hpp kf_1dim_tl.cpp
	$(CXX) -c kf_1dim_tl.cpp -o kf_1dim_tl.o

clean:
	rm kf_1dim_tl.o pykalman.so
