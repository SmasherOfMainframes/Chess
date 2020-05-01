#ifndef __KING_CHECK__
#define __KING_CHECK__

int king_check(int _team, std::string &_error_msg){
	std::vector<std::vector<int>> king_vec;
	int king_coord;
	if(_team == 1){
		king_coord = KING_COORD_W;
		check_vec_w.clear();
	} else {
		king_coord = KING_COORD_B;
		check_vec_b.clear();
	}


	// Check if Bishop or Queen can capture
	bshp_moves(king_vec, _team, king_coord, true);
	apply_moves(king_vec, king_coord);
	clear_moves(king_vec, king_coord);

	// Check if Rook or Queen can capture
	rook_moves(king_vec, _team, king_coord, true);
	apply_moves(king_vec, king_coord);
	clear_moves(king_vec, king_coord);
	

	if(_team == 1 && check_vec_w.size() > 0){
		_error_msg = "Causes check!\n";
		return 1;
	} else if(_team == -1 && check_vec_b.size() > 0){
		_error_msg = "Causes check!\n";
		return 1;
	} else {
		_error_msg = "";
		return 0;
	}
}


#endif