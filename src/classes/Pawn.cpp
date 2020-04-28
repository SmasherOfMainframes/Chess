#include "Pawn.hpp"

Pawn::Pawn(int _rank, char _c, int _own)
: Piece(_rank, _c, _own), first_move{true} {
	
}

int Pawn::pawn_promotion(char new_rank){
	switch(new_rank){
		case 'p':
			return 0;
			break;
		case 'R':
			rank = 2;
			symbol = 'R';
			return 1;
			break;
		case 'K':
			rank = 3;
			symbol = 'K';
			return 1;
			break;
		case 'B':
			rank = 4;
			symbol = 'B';
			return 1;
			break;
		case 'Q':
			rank = 5;
			symbol = 'Q';
			return 1;
			break;
		case '$':
			return 0;
			break;
		default:
			return 0;
			break;
	}
}

bool Pawn::get_first_move(){
	return first_move;
}
void Pawn::set_first_move(bool _b){
	first_move = _b;
}