#include "Piece.hpp"

Piece::Piece(int _rank, char _c, int _own)
: rank{_rank}, symbol{_c}, owner{_own}, coord{-2} {

}
Piece::~Piece(){
	// std::cerr << "PIECE DESTRUCTOR CALLED\n";
	// std::cerr << this << "\n";
	// std::cerr << coord << "\n";
	// std::cerr << rank << "\n";
}

int Piece::get_coord(){
	return(coord);
}
void Piece::set_coord(int new_coord){
	coord = new_coord;
}

int Piece::get_rank(){
	return rank;
}
int Piece::get_owner(){
	return owner;
}
char Piece::get_symbol(){
	return symbol;
}
// void Piece::set_symbol(char _c){
// 	symbol = _c;
// }

bool Piece::get_first_move(){
	return{true};
}
void Piece::set_first_move(bool _b){
	  
}
int Piece::pawn_promotion(char new_rank){
	  return 0;
}