all:
	g++ main.cpp ./view/*.cpp ./model/*.cpp ./controller/*.cpp -o ./bin/game \
		-std=c++11 -lsfml-graphics -lsfml-window -lsfml-system

run: all
	./bin/game &
