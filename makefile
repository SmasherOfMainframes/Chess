main.exe: main.o Coordinate.o Piece.o
	g++ main.o Coordinate.o Piece.o -o main.exe

main.o: main.cpp init_board.hpp narrator.hpp setup_fns.hpp draw_fns.hpp coord_conversion.hpp
	g++ -c main.cpp

Coordinate.o: Coordinate.cpp Coordinate.hpp
	g++ -c Coordinate.cpp

Piece.o: Piece.cpp Piece.hpp
	g++ -c Piece.cpp

clean:
	rm *.o main.exe