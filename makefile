objects = main.o\
		  Coordinate.o\
		  Piece.o\
		  Pawn.o

publics = src/public/*
movesets = src/movesets/*

VPATH = src/classes src/public src/movesets bin

main.exe: $(objects)
	g++ $(objects) -o main.exe

main.o: $(publics) $(movesets)

Coordinate.o: Coordinate.hpp

Piece.o: Piece.hpp

Pawn.o: Pawn.hpp Piece.cpp Piece.hpp

clean:
	rm $(objects) main.exe