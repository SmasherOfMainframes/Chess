#include "Piece.hpp"

Piece::Piece(int _rank, char _c, int _own)
: rank{_rank}, symbol{_c}, owner{_own} {

}
Piece::~Piece(){
	std::cout << "DESTRUCTOR CALLED" << std::endl;
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