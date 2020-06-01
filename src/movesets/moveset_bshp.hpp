#ifndef __BSHP_MS__
#define __BSHP_MS__

bool is_barrier(int _coord1, int _coord2, int _team, bool _king_check);
// bool king_check(int _team);

void bshp_moves(std::vector<std::vector<int>> &_vec, int &_team, int _coord, bool vking_check){

	int y_coord{(_coord/8) + 1};	// 1 - 8, NOT 0 - 7
	int x_coord{(_coord%8) + 1};	// 1 - 8, NOT 0 - 7

	int temp_min;

	int temp_coord;
	int temp_rank;
	int temp_team;

	int _coord2;

	// check whether piece is closer to right edge or top edge
	// then appends (+X, +Y) moves
	temp_min = std::min(8-x_coord, 8-y_coord);

	for(int i = 0; i < temp_min; i++){
		
		temp_coord = _coord+9+(i*9);
		temp_team = main_board.at(temp_coord).get_tenant_team();
		temp_rank = main_board.at(temp_coord).get_tenant_rank();

		if(team_obstruction(temp_coord, _team)){break;}
		_coord2 = _coord + (i+1) + (8*(i+1));
		if(!is_barrier(_coord, _coord2, _team, vking_check)){
			_vec.push_back(std::vector<int>{i+1, i+1});
		}
		if(enmy_obstruction(temp_coord, _team)){
			if(vking_check && temp_team != _team && ((temp_rank == 4) || (temp_rank == 5)) ){
				if(_team == 1){
					check_vec_w.push_back(0);
				} else {
					check_vec_b.push_back(0);
				}
			}
			break;
		}
	}

	// check whether piece is closer to right edge or bottom edge
	// then appends (+X, -Y) moves
	temp_min = std::min(8-x_coord, y_coord - 1);

	for(int i = 0; i < temp_min; i++){
		
		temp_coord = _coord-7-(i*7);
		temp_team = main_board.at(temp_coord).get_tenant_team();
		temp_rank = main_board.at(temp_coord).get_tenant_rank();

		if(team_obstruction(temp_coord, _team)){break;}
		_coord2 = _coord + (i+1) + (8*((-1*i) - 1));
		if(!is_barrier(_coord, _coord2, _team, vking_check)){
			_vec.push_back(std::vector<int>{i+1, (-1*i)-1});
		}
		if(enmy_obstruction(temp_coord, _team)){
			if(vking_check && temp_team != _team && ((temp_rank == 4) || (temp_rank == 5)) ){
				if(_team == 1){
					check_vec_w.push_back(0);
				} else {
					check_vec_b.push_back(0);
				}
			}
			break;
		}
	}

	// check whether piece is closer to left edge or top edge
	// then appends (-X, +Y) moves
	temp_min = std::min(x_coord - 1, 8-y_coord);

	for(int i = 0; i < temp_min; i++){
		
		temp_coord = _coord+7+(i*7);
		temp_team = main_board.at(temp_coord).get_tenant_team();
		temp_rank = main_board.at(temp_coord).get_tenant_rank();

		if(team_obstruction(temp_coord, _team)){break;}
		_coord2 = _coord + ((-1*i)-1) + (8*(i+1));
		if(!is_barrier(_coord, _coord2, _team, vking_check)){
			_vec.push_back(std::vector<int>{(-1*i)-1, i+1});
		}
		if(enmy_obstruction(temp_coord, _team)){
			if(vking_check && temp_team != _team && ((temp_rank == 4) || (temp_rank == 5)) ){
				if(_team == 1){
					check_vec_w.push_back(0);
				} else {
					check_vec_b.push_back(0);
				}
			}
			break;
		}
	}

	// check whether piece is closer to left edge or top edge
	// then appends (-X, -Y) moves
	temp_min = std::min(x_coord - 1, y_coord - 1);

	for(int i = 0; i < temp_min; i++){
		
		temp_coord = _coord-9-(i*9);
		temp_team = main_board.at(temp_coord).get_tenant_team();
		temp_rank = main_board.at(temp_coord).get_tenant_rank();

		if(team_obstruction(temp_coord, _team)){break;}
		_coord2 = _coord + ((-1*i)-1) + (8*((-1*i)-1));
		if(!is_barrier(_coord, _coord2, _team, vking_check)){
			_vec.push_back(std::vector<int>{(-1*i)-1, (-1*i)-1});
		}
		if(enmy_obstruction(temp_coord, _team)){
			if(vking_check && temp_team != _team && ((temp_rank == 4) || (temp_rank == 5)) ){
				if(_team == 1){
					check_vec_w.push_back(0);
				} else {
					check_vec_b.push_back(0);
				}
			}
			break;
		}
	}
	
}


#endif