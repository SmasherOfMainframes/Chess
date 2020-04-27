#ifndef __PAWN__
#define __PAWN__

#include "Piece.hpp"

class Pawn : public Piece
{
	private:
		bool can_capture;
		bool first_move;
	
	public:
		Pawn(int, char, int);

		bool get_capture_state();
		void set_capture_state(bool);

		bool get_first_move();
		void set_first_move(bool);

};


#endif