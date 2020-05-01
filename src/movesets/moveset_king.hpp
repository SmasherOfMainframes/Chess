#ifndef __KING_MS__
#define __KING_MS__

void king_moves(std::vector<std::vector<int>> &_vec, int &_team, int _coord){
	for(int x = -1; x < 2; x++){
		for(int y = -1; y < 2; y++){
			if(
				!(x == 0 && y == 0)
				&&
				!wrapping_x(_coord, x)
				&&
				!out_bounds_y(_coord, y)
				&&
				!team_obstruction(_coord + x + (8*y), _team)
				){
				_vec.push_back(std::vector<int>{x, y});
			}
		}
	}
}

#endif