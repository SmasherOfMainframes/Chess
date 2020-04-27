#include "Coordinate.hpp"

Coordinate::Coordinate(int _x, int _y, char _c)
: pos_x{_x}, pos_y{_y}, default_charset{_c}, charset{_c}, 
  tenant{nullptr}, charset_color{"\033[0m"} {

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
	charset_color = "\033[0m";
}

void Coordinate::print_generic(){
	std::cout << get_charset_color() << get_charset() 
			  << get_charset_color() << get_charset()
			  << get_charset_color() << get_charset() 
			  << get_charset_color() << get_charset()
			  << get_charset_color() << get_charset()
			  << RESET;
}
void Coordinate::print_unique(){
	std::cout << get_charset_color() << get_charset() 
			  << get_charset_color() << get_charset() 
			  << get_tenant_team_color() << get_tenant_symbol() 
			  << get_charset_color() << get_charset()
			  << get_charset_color() << get_charset()
			  << RESET; 
}

std::string Coordinate::get_tenant_team_color(){
	int team {get_tenant_team()};
	if(team == 1){
		return CYAN;
	} else if(team == -1){
		return MAGENTA;
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
int Coordinate::get_tenant_rank(){
	return tenant -> get_rank();
}
void Coordinate::set_tenant(Piece* ptr){
	tenant = ptr;
}
void Coordinate::move_tenant(Coordinate &new_coord){
	new_coord.set_tenant(tenant);
	set_tenant(nullptr);
}