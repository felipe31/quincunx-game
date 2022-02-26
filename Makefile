all:
	g++ -std=c++11 main.cpp -o ./bin/game -lsfml-graphics -lsfml-window -lsfml-system

run: all
	./bin/game &


test-build:
	cmake -S . -B build
	cmake --build build

test-run:
	cd build && ctest

test: test-build test-run