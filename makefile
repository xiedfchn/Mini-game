CC=g++
CFLAGS=-I.

all:
	$(CC) -o out Main.cpp Var.h Item.h Item.cpp Character.h Character.cpp Map.h Map.cpp Control.h Control.cpp -I -std=gnu++11
clean:
	rm *.o
