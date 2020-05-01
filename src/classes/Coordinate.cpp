#include "Coordinate.hpp"

Coordinate::Coordinate(int _x, int _y, char _c)
: pos_x{_x}, pos_y{_y}, default_charset{_c}, charset{_c}, 
  tenant{nullptr} {
  	if(charset == WHT_TILE_CHAR){
  		default_char_col = WHT_TILE_COL;
  	} else {
		default_char_col = BLK_TILE_COL;
	}
	charset_color = default_char_col;
}

Piece* Coordinate::get_tenant(){
	return tenant;
}


int Coordinate::get_x(){
	return pos_x;
}
int Coordinate::get_y(){
	return pos_y;
}


char Coordinate::get_charset(){
	return charset;
}
void Coordinate::set_charset(char _c){
	charset = _c;
}
void Coordinate::reset_charset(){
	charset = default_charset;
}

void Coordinate::set_charset_color(std::string new_col){
	charset_color = new_col;
}
std::string Coordinate::get_charset_color(){
	return charset_color;
}
void Coordinate::reset_charset_color(){
	charset_color = default_char_col;
}

void Coordinate::print_generic(){
	std::cout << get_charset_color() << get_charset() 
			  << get_charset_color() << get_charset()
			  << get_charset_color() << get_charset() 
			  << get_charset_color() << get_charset()
			  << get_charset_color() << get_charset()
			  << GAME_COL;
}
void Coordinate::print_unique(){
	std::cout << get_charset_color() << get_charset() 
			  << get_charset_color() << get_charset() 
			  << get_tenant_team_color() << get_tenant_symbol() 
			  << get_charset_color() << get_charset()
			  << get_charset_color() << get_charset()
			  << GAME_COL;
}

std::string Coordinate::get_tenant_team_color(){
	int team {get_tenant_team()};
	if(team == 1){
		return TEAMW_COL;
	} else if(team == -1){
		return TEAMB_COL;
	} else {
		return get_charset_color();
	}
}
int Coordinate::get_tenant_team(){
	if(tenant){
		return tenant -> get_owner();
	}
	return -2;
}
char Coordinate::get_tenant_symbol(){
	if(!tenant){
		return get_charset();
	} else {
		return tenant -> get_symbol();
	}
}
// void Coordinate::set_tenant_symbol(char _c){
// 	if(!tenant){
// 		//
// 	} else {
// 		tenant -> set_symbol(_c);
// 	}
// }
int Coordinate::get_tenant_rank(){
	if(tenant){
		return tenant -> get_rank();
	} else {
		return 0;
	}
	
}
void Coordinate::set_tenant(Piece* ptr){
	tenant = ptr;
	if(tenant){
		tenant -> set_coord((pos_x-1) + ((pos_y-1)*8));
	}
}
void Coordinate::set_tenant_coord(int new_coord){
	if(tenant){
		tenant -> set_coord(new_coord);	
	}
}
int Coordinate::get_tenant_coord(){
	if(tenant){
		return(tenant -> get_coord());
	} else {
		return (-5000);
	}
}
void Coordinate::move_tenant(Coordinate &new_coord){
	new_coord.set_tenant_coord(-2);
	new_coord.set_tenant(tenant);
	set_tenant(nullptr);
}

bool Coordinate::get_tenant_first_move(){
	return tenant -> get_first_move();
}
void Coordinate::set_tenant_first_move(bool _b){
	tenant -> set_first_move(_b);
}

int Coordinate::tenant_pawn_promotion(char new_rank){
	return(tenant -> pawn_promotion(new_rank));
}