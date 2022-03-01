all:
	g++ main.cpp ./view/*.cpp ./model/*.cpp ./controller/*.cpp -o ./bin/game \
		-std=c++11 -lsfml-graphics -lsfml-window -lsfml-system

run: all
	./bin/game &


test-build:
	cmake -S . -B build
	cmake --build build

test-run:
	cd build && ctest

test: test-build test-run