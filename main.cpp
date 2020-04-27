// CHESS
#include <iostream>
#include <vector>
#include <string>

#define RESET   "\033[0m"
#define WHITE   "\033[37m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

#include "Piece.hpp"
#include "Coordinate.hpp"

#include "init_board.hpp"	// initializes board
#include "draw_fns.hpp"		// functions for drawing and creates main objects of Coordinate
#include "setup_fns.hpp"
#include "coord_conversion.hpp"
#include "narrator.hpp"


int main(){

	initialize_regular();

	bool run {true};
	// bool run {false};

	system("clear");

	while(run){
		title();
		draw_board();
		narrator();
		system("clear");
	}

	// std::cout << "\033[35m" << "hello world" << RESET << std::endl;


	return 0;
}