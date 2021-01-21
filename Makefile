wumpus_run:
	g++ wumpus_game.cpp game.cpp room.cpp event.cpp player.cpp wumpus.cpp gold.cpp bats.cpp pit.cpp -o wumpus_run

CC=g++
EXE_FILE=wumpus_run
all: $(EXE_FILE)
$(EXE_FILE): wumpus_game.cpp game.o room.o event.o player.o wumpus.o gold.o bats.o pit.o
	$(CC) wumpus_game.cpp game.o room.o event.o player.o wumpus.o gold.o bats.o pit.o -o $(EXE_FILE)
game.o: game.cpp game.h
	$(CC) -c game.cpp
room.o: room.cpp room.h
	$(CC) -c room.cpp
event.o: event.cpp event.h
	$(CC) -c event.cpp
player.o: player.cpp player.h
	$(CC) -c player.cpp
wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp
gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp
bats.o: bats.cpp bats.h
	$(CC) -c bats.cpp
pit.o: pit.cpp pit.h
	$(CC) -c pit.cpp

clean:
	rm -f *.o $(EXE_FILE)