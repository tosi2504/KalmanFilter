CXX = clang++
INC_PYBIND = -I ~/.local/lib/python3.8/site-packages/pybind11/include
INC_PYCONFIG = -I /usr/include/python3.8

pykalman: kf_1dim_tl.o pykalman.cpp kf_1dim_rot.o
	$(CXX) -Wall -shared -fPIC $(INC_PYBIND) $(INC_PYCONFIG) kf_1dim_tl.o kf_1dim_rot.o pykalman.cpp -o pykalman.so

kf_1dim_tl.o: kalmanfilters.hpp kf_1dim_tl.cpp
	$(CXX) -c kf_1dim_tl.cpp -o kf_1dim_tl.o

kf_1dim_rot.o: kalmanfilters.hpp kf_1dim_rot.cpp
	$(CXX) -c kf_1dim_rot.cpp -o kf_1dim_rot.o


clean:
	rm kf_1dim_tl.o pykalman.so kf_1dim_rot.o
	make clean -C lib/math3D

build_lib:
	make -C lib/math3D/
