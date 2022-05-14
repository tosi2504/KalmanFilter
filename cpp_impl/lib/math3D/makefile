all: vec3D.o mat3D.o
	echo "Building vec3D.o and mat3D.o"


test: math3D.hpp mat3D.o test.cpp vec3D.o
	g++ -Wall -Wextra -Wpedantic -o run vec3D.o mat3D.o  test.cpp

vec3D.o: math3D.hpp vec3D.cpp
	g++ -Wall -Wextra -Wpedantic -o vec3D.o -c vec3D.cpp -fPIC

mat3D.o: math3D.hpp mat3D.cpp
	g++ -Wall -Wextra -Wpedantic -o mat3D.o -c mat3D.cpp -fPIC

clean:
	rm vec3D.o mat3D.o
