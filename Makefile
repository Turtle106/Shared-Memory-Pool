all:
	g++ -std=c++20 Main.cpp NPC.cpp -Wall -Werror -o main
debug:
	g++ -std=c++20 Main.cpp NPC.cpp -O0 -g -o debug
clean:
	rm -f main debug
