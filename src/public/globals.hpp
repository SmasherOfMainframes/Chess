#ifndef __GLOBALS__
#define __GLOBALS__

#define RESET   "\033[0m"
#define WHITE   "\033[37m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define YELLOW  "\033[33m"

// GLOBALS

std::string TEAMW_COL	 	{CYAN}; 	// Team 1
std::string TEAMB_COL 		{MAGENTA};	// Team -1

char BLK_TILE_CHAR 			{':'};
char WHT_TILE_CHAR 			{' '};
char SELF_TILE_CHAR 		{'-'};
char MOVES_TILE_CHAR 		{'+'};
std::string MOVES_TILE_COL 	{YELLOW};

#endif