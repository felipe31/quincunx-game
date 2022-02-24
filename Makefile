all:
	g++ main.cpp -o ./bin/game -lsfml-graphics -lsfml-window -lsfml-system

run: all
	./bin/game &
