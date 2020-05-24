#ifndef __GLOBALS__
#define __GLOBALS__

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m" 

// GLOBALS - Don' assign same tile colors

std::string TEAMW_COL	 	{CYAN}; 	// Team 1
std::string TEAMB_COL 		{MAGENTA};		// Team -1

std::string TEAMW_NAME		{"Cyan"};
std::string TEAMB_NAME		{"Magenta"};

char WHT_TILE_CHAR 			{' '};
char BLK_TILE_CHAR 			{':'};

std::string WHT_TILE_COL	{WHITE};
std::string BLK_TILE_COL	{BLACK};

char SELF_TILE_CHAR 		{'-'};

char MOVES_TILE_CHAR 		{'+'};
std::string MOVES_TILE_COL 	{YELLOW};

std::string GAME_COL		{WHITE};

#endif
