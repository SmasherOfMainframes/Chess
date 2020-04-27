#ifndef __CLASS_COORDINATE__
#define __CLASS_COORDINATE__

#include <vector>
#include <iostream>
#include <string>

#include "Piece.hpp"

#define RESET   "\033[0m"
#define WHITE   "\033[37m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

class Coordinate
{
	private:
		const int pos_x;
		const int pos_y;

		char charset;					// the characters that indicate black or white board tile
		const char default_charset;		// default character
		std::string charset_color;

		std::vector<char> generic;
		std::vector<char> unique;

		Piece* tenant;

	public:
		Coordinate(int, int, char);

		int get_x();
		int get_y();

		char get_charset();				// returns current charset
		void set_charset(char);			// sets charset
		void reset_charset();			// rests charset to default charset

		void set_charset_color(std::string);
		void reset_charset_color();
		std::string get_charset_color();

		void print_generic();			// used to print out the top or bottom row of board coordinate
		void print_unique();			// used to print out the middle row of the board coordinate

		std::string get_tenant_team_color();
		int get_tenant_team();
		char get_tenant_symbol();		// gets the symbol of current piece, if there is one
		int get_tenant_rank();
		void set_tenant(Piece*);		// associates a piece
		void move_tenant(Coordinate&);	// moves piece
};



#endif