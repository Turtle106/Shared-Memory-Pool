all:
	g++ Main.cpp NPCPool.cpp npc.cpp -Wall -Werror -o main
debug:
	g++ Main.cpp NPCPool.cpp npc.cpp -O0 -g -o debug
clean:
	rm -f main debug
