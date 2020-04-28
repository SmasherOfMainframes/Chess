#ifndef __BSHP_MS__
#define __BSHP_MS__


void bshp_moves(std::vector<std::vector<int>> &_vec, int &_team, int _coord){

	int y_coord{(_coord/8) + 1};	// 1 - 8, NOT 0 - 7
	int x_coord{(_coord%8) + 1};	// 1 - 8, NOT 0 - 7

	int temp_min;

	// check whether piece is closer to right edge or top edge
	// then appends (+X, +Y) moves
	temp_min = std::min(8-x_coord, 8-y_coord);

	for(int i = 0; i < temp_min; i++){
		if(team_obstruction(_coord+9+(i*9), _team)){break;}
		_vec.push_back(std::vector<int>{i+1, i+1});
		if(enmy_obstruction(_coord+9+(i*9), _team)){break;}
	}

	// check whether piece is closer to right edge or bottom edge
	// then appends (+X, -Y) moves
	temp_min = std::min(8-x_coord, y_coord - 1);

	for(int i = 0; i < temp_min; i++){
		if(team_obstruction(_coord-7-(i*7), _team)){break;}
		_vec.push_back(std::vector<int>{i+1, (-1*i)-1});
		if(enmy_obstruction(_coord-7-(i*7), _team)){break;}
	}

	// check whether piece is closer to left edge or top edge
	// then appends (-X, +Y) moves
	temp_min = std::min(x_coord - 1, 8-y_coord);

	for(int i = 0; i < temp_min; i++){
		if(team_obstruction(_coord+7+(i*7), _team)){break;}
		_vec.push_back(std::vector<int>{(-1*i)-1, i+1});
		if(enmy_obstruction(_coord+7+(i*7), _team)){break;}
	}

	// check whether piece is closer to left edge or top edge
	// then appends (-X, -Y) moves
	temp_min = std::min(x_coord - 1, y_coord - 1);

	for(int i = 0; i < temp_min; i++){
		if(team_obstruction(_coord-9-(i*9), _team)){break;}
		_vec.push_back(std::vector<int>{(-1*i)-1, (-1*i)-1});
		if(enmy_obstruction(_coord-9-(i*9), _team)){break;}
	}
	
}


#endif