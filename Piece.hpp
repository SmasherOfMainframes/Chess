#ifndef __CLASS_PIECE__
#define __CLASS_PIECE__

#include <vector>
#include <iostream>

/*
Pawn = 1
Rook = 2
Knht = 3
Bshp = 4
Quen = 5
King = 6
*/

class Piece
{
	private:
		const int rank;
		const char symbol;
		const int owner;

	public:
		Piece(int, char, int);
		~Piece();

		int get_rank();
		int get_owner();
		char get_symbol();

		// virtual bool get_capture_state();
		// virtual void set_capture_state(bool);

		// virtual bool get_first_move();
		// virtual void set_first_move(bool);
};

#endif