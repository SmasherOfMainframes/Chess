#include "Pawn.hpp"

Pawn::Pawn(int _rank, char _c, int _own)
: Piece(_rank, _c, _own), first_move{true} {
	
}

bool Pawn::get_first_move(){
	return first_move;
}
void Pawn::set_first_move(bool _b){
	first_move = _b;
}