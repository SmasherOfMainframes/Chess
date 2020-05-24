#ifndef __KING_CHECK__
#define __KING_CHECK__

bool king_check(int _team, std::string &_error_msg){
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

	// Check if Knight can capture
	kngt_moves(king_vec, _team, king_coord, true);
	apply_moves(king_vec, king_coord);
	clear_moves(king_vec, king_coord);

	// Check if Pawn can capture
	pawn_moves(king_vec, _team, king_coord, true);
	apply_moves(king_vec, king_coord);
	clear_moves(king_vec, king_coord);

	// Check if other King can capture
	king_moves(king_vec, _team, king_coord, true);
	apply_moves(king_vec, king_coord);
	clear_moves(king_vec, king_coord);
	

	if(_team == 1 && check_vec_w.size() > 0){
		_error_msg = "Causes check!\n";
		return true;
	} else if(_team == -1 && check_vec_b.size() > 0){
		_error_msg = "Causes check!\n";
		return true;
	} else {
		_error_msg = "";
		return false;
	}
}


void check_checkmate(int _team){
	std::vector<std::vector<int>> temp_move_vec;
	if(_team == 1 && check_vec_w.size() > 0){
		std::cerr << "TEAM W\n";
		for(size_t i = 0; i < teamW.size(); i++){
			int temp_coord = teamW.at(i) -> get_coord();
			std::cerr << temp_coord << "\n";
		}
		std::cerr << "------------\n";
	}
	if(_team == -1 && check_vec_b.size() > 0){
		std::cerr << "TEAM B\n";
		for(size_t i = 0; i < teamB.size(); i++){
			int temp_coord = teamB.at(i) -> get_coord();
			std::cerr << temp_coord << "\n";
		}
		std::cerr << "------------\n";
	}
}


#endif