#ifndef __ROOK_MS__
#define __ROOK_MS__


void rook_moves(std::vector<std::vector<int>> &_vec, int &_team, int _coord, bool king_check){

	int temp_coord;
	int temp_rank;
	int temp_team;

	for(int i = 0; i < (7-(_coord%8)); i++){
		
		temp_coord = _coord+1+i;
		temp_team = main_board.at(temp_coord).get_tenant_team();
		temp_rank = main_board.at(temp_coord).get_tenant_rank();

		if(team_obstruction(temp_coord, _team)){break;}
		_vec.push_back(std::vector<int>{i+1, 0});
		if(enmy_obstruction(temp_coord, _team)){
			if(king_check && temp_team != _team && ((temp_rank == 2) || (temp_rank == 5)) ){
				if(_team == 1){
					check_vec_w.push_back(0);
				} else {
					check_vec_b.push_back(0);
				}
			}
			break;
		}
	}
	for(int i = 0; i < _coord%8 ; i++){
		
		temp_coord = _coord-1-i;
		temp_team = main_board.at(temp_coord).get_tenant_team();
		temp_rank = main_board.at(temp_coord).get_tenant_rank();

		if(team_obstruction(temp_coord, _team)){break;}
		_vec.push_back(std::vector<int>{(-1*i)-1, 0});
		if(enmy_obstruction(temp_coord, _team)){
			if(king_check && temp_team != _team && ((temp_rank == 2) || (temp_rank == 5)) ){
				if(_team == 1){
					check_vec_w.push_back(0);
				} else {
					check_vec_b.push_back(0);
				}
			}
			break;
		}
	}

	for(int i = 0; i < 8-((_coord/8)+1); i++){
		
		temp_coord = _coord+8+(8*i);
		temp_team = main_board.at(temp_coord).get_tenant_team();
		temp_rank = main_board.at(temp_coord).get_tenant_rank();

		if(team_obstruction(temp_coord, _team)){break;}
		_vec.push_back(std::vector<int>{0, i+1});
		if(enmy_obstruction(temp_coord, _team)){
			if(king_check && temp_team != _team && ((temp_rank == 2) || (temp_rank == 5)) ){
				if(_team == 1){
					check_vec_w.push_back(0);
				} else {
					check_vec_b.push_back(0);
				}
			}
			break;
		}
	}
	for(int i = 0; i < (_coord/8); i++){
		
		temp_coord = _coord-8-(8*i);
		temp_team = main_board.at(temp_coord).get_tenant_team();
		temp_rank = main_board.at(temp_coord).get_tenant_rank();

		if(team_obstruction(temp_coord, _team)){break;}
		_vec.push_back(std::vector<int>{0, (-1*i)-1});
		if(enmy_obstruction(temp_coord, _team)){
			if(king_check && temp_team != _team && ((temp_rank == 2) || (temp_rank == 5)) ){
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