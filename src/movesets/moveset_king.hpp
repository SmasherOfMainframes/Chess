#ifndef __KING_MS__
#define __KING_MS__

bool king_check(int _team);

void king_moves(std::vector<std::vector<int>> &_vec, int &_team, int _coord, bool _king_check){
	int temp_coord;
	int temp_rank;
	int temp_team;

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
				) { 
				// need to add king_check() for each move to prevent invalid moves
				// from being added to move vector. 
				int temp_king_coord_w = KING_COORD_W;
				int temp_king_coord_b = KING_COORD_B;
				
				KING_COORD_W += (x + (8*y));
				KING_COORD_B += (x + (8*y));

				if((!_king_check) && !(king_check(_team))){
					_vec.push_back(std::vector<int>{x, y});
				}

				KING_COORD_W = temp_king_coord_w;
				KING_COORD_B = temp_king_coord_b;

				temp_coord = _coord + x + (8*y);
				temp_team = main_board.at(temp_coord).get_tenant_team();
				temp_rank = main_board.at(temp_coord).get_tenant_rank();

				if(_king_check && temp_team != _team && temp_rank == 6 ){
					if(_team == 1){
						check_vec_w.push_back(0);
					} else {
						check_vec_b.push_back(0);
					}
				}
			}
		}
	}
}

#endif