#ifndef __PAWN__
#define __PAWN__

#include "Piece.hpp"

class Pawn : public Piece
{
	private:
		bool first_move;
	
	public:
		Pawn(int, char, int);

		virtual bool get_first_move() final override;
		virtual void set_first_move(bool) final override;
};


#endif