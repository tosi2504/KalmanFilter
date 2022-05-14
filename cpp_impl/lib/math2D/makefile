all: mat2D.o # vec2D.o
	echo "Building vec2D.o and mat2D.o"

# vec2D.o: math2D.hpp vec2D.cpp
# 	g++ -Wall -Wextra -Wpedantic -o vec2D.o -c vec2D.cpp -fPIC

mat2D.o: math2D.hpp mat2D.cpp
	g++ -Wall -Wextra -Wpedantic -o mat2D.o -c mat2D.cpp -fPIC

clean:
	rm vec2D.o mat2D.o
