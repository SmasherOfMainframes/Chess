CC 			= g++

VPATH 		= src/classes src/public src/movesets bin

CPPFLAGS 	= -g -Wall

OBJS 		= 	main.o\
		  		Coordinate.o\
		  		Piece.o\
		  		Pawn.o

PUBLIC 		= src/public/*
MOVESET 	= src/movesets/*

OUTPUT 		= bin/main

$(OUTPUT): $(OBJS)
	$(CC) $(OBJS) -o $(OUTPUT)

main.o: $(PUBLIC) $(MOVESET)

Coordinate.o: Coordinate.hpp

Piece.o: Piece.hpp

Pawn.o: Pawn.hpp Piece.cpp Piece.hpp

clean:
	rm $(OBJS) $(OUTPUT)

run:
	./bin/main

