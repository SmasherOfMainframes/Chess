main.exe: main.o Coordinate.o Piece.o
	g++ main.o Coordinate.o Piece.o -o main.exe

main.o: main.cpp
	g++ -c main.cpp

Coordinate.o: Coordinate.cpp Coordinate.hpp
	g++ -c Coordinate.cpp

Piece.o: Piece.cpp Piece.hpp
	g++ -c Piece.cpp

clean:
	rm *.o main.exe