#ifndef __DISPLAY_MOVES__
#define __DISPLAY_MOVES__

/*
Pawn = 1
Rook = 2
Knht = 3
Bshp = 4
Quen = 5
King = 6
*/

void display_moves(int _coord, int _turn, std::string _phase){
	static std::vector<std::vector<int>> move_vec;
	if(_phase == "coord1"){
		move_vec.clear();

		int _team = main_board.at(_coord).get_tenant_team();
		int _rank = main_board.at(_coord).get_tenant_rank();

		switch(_rank){

			case 1: // Pawn
				pawn_moves(move_vec, _team, _coord);
				break;

			case 2: // Rook
				rook_moves(move_vec, _team, _coord);
				break;

			case 3:
				// ---
				break;
			
			case 4: // Bishop
				bshp_moves(move_vec, _team, _coord);
				break;

			case 5: // Queen
				quen_moves(move_vec, _team, _coord);
				break;

			case 6:
				// ---
				break;

		}

		// Set temporary unique charset for selected piece
		main_board.at(_coord).set_charset(SELF_TILE_CHAR);
		main_board.at(_coord).set_charset_color(MOVES_TILE_COL);

		// Set tiles of possible moves to special character/color
		for(size_t i = 0; i < move_vec.size(); i++){
			int temp_coord = _coord + move_vec.at(i).at(0) + (8 * move_vec.at(i).at(1));
			main_board.at(temp_coord).set_charset(MOVES_TILE_CHAR);
			main_board.at(temp_coord).set_charset_color(MOVES_TILE_COL);
		}
	} else {
		for(size_t i = 0; i < move_vec.size(); i++){
			int temp_coord = _coord + move_vec.at(i).at(0) + (8 * move_vec.at(i).at(1));
			main_board.at(temp_coord).reset_charset();
			main_board.at(temp_coord).reset_charset_color();
		}
		main_board.at(_coord).reset_charset();
		main_board.at(_coord).reset_charset_color();
	}
}


#endif