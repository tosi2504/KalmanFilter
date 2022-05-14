CXX = clang++
INC_PYBIND = -I ~/.local/lib/python3.8/site-packages/pybind11/include
INC_PYCONFIG = -I /usr/include/python3.8
INC_MATH3D = -I ~/Documents/excav_tools/KalmanFilter/cpp_impl/lib/math3D
INC_MATH2D = -I ~/Documents/excav_tools/KalmanFilter/cpp_impl/lib/math2D

pykalman: pykalman.cpp kalmanfilters.hpp kf_1dim_tl.o kf_1dim_rot.o kf_3dim_tl.o
	$(CXX) $(INC_PYBIND) $(INC_PYCONFIG) $(INC_MATH3D) $(INC_MATH2D) -Wall -shared -fPIC kf_1dim_tl.o kf_1dim_rot.o kf_3dim_tl.o pykalman.cpp -o pykalman.so

kf_3dim_tl.o: kalmanfilters.hpp kf_3dim_tl.cpp
	$(CXX) $(INC_MATH3D) $(INC_MATH2D) -c kf_3dim_tl.cpp -o kf_3dim_tl.o

kf_1dim_tl.o: kalmanfilters.hpp kf_1dim_tl.cpp
	$(CXX) $(INC_MATH3D) $(INC_MATH2D) -c kf_1dim_tl.cpp -o kf_1dim_tl.o

kf_1dim_rot.o: kalmanfilters.hpp kf_1dim_rot.cpp
	$(CXX) $(INC_MATH3D) $(INC_MATH2D) -c kf_1dim_rot.cpp -o kf_1dim_rot.o

transform.o: kalmanfilters.hpp transform.cpp
	$(CXX) $(INC_MATH3D) $(INC_MATH2D) -c transform.cpp -o transform.o lib/math3D/vec3D.o



clean:
	rm kf_1dim_tl.o pykalman.so kf_1dim_rot.o
	make clean -C lib/math3D

build_lib:
	make -C lib/math3D/
