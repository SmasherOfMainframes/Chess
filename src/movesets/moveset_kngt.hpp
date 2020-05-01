#ifndef __KNIGHT_MS__
#define __KNIGHT_MS__

// Loops through all possible knight move combinations
// (+- x , +- y) where x, y element of {+- 1, +- 2} && |x| != |y| 

void kngt_moves(std::vector<std::vector<int>> &_vec, int &_team, int _coord){
	for(int x = -2; x < 3; x++){
		if(x!=0){
			for(int y = -2; y < 3; y++){
				if(y!=0 && abs(x)!=abs(y)){
					if(
						!wrapping_x(_coord, x)
						&&
						!out_bounds_y(_coord, y)
						&&
						!team_obstruction(_coord + x + (8*y), _team)
						) {
						_vec.push_back(std::vector<int>{x, y});
					}
				}
			}
		}
	}
}




#endif