#ifndef __CLASS_COORDINATE__
#define __CLASS_COORDINATE__

#include <vector>
#include <iostream>
#include <string>

#include "Piece.hpp"

extern std::string TEAMW_COL;
extern std::string TEAMB_COL;

extern std::string WHT_TILE_COL;
extern std::string BLK_TILE_COL;

extern char WHT_TILE_CHAR;
extern char BLK_TILE_CHAR;

extern std::string GAME_COL;

class Coordinate
{
	private:
		const int pos_x;
		const int pos_y;

		char charset;					// the characters that indicate black or white board tile
		const char default_charset;		// default character
		
		std::string charset_color;
		std::string default_char_col;

		std::vector<char> generic;
		std::vector<char> unique;

		Piece* tenant;

	public:
		Coordinate(int, int, char);

		Piece* get_tenant();

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
		// void set_tenant_symbol(char);
		int get_tenant_rank();
		
		void set_tenant(Piece*);		// associates a piece
		int get_tenant_coord();
		void set_tenant_coord(int);
		void move_tenant(Coordinate&);	// moves piece

		bool get_tenant_first_move();
		void set_tenant_first_move(bool);

		int tenant_pawn_promotion(char);
};



#endif