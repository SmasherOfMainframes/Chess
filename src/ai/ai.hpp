#ifndef __AI__
#define __AI__

#include <limits>
#include <utility>

// White wants highly positive values
// Black wants highly negative values

int get_board_value(){
	int value {0};
	for(size_t i = 0; i < teamW.size(); i++){
		if(teamW.at(i) -> get_coord() != -2){
			value += teamW.at(i)->get_value();
		}
	}
	for(size_t i = 0; i < teamB.size(); i++){
		if(teamB.at(i) -> get_coord() != -2){
			value += teamB.at(i)->get_value();
		}
	}
	return value;
}

// store a std::vector<std::vector<int>> of coordinate 1 and coordinate 2 ez pz
std::vector<std::vector<int>> all_moves(int _team){

	std::vector<std::vector<int>> ALL_MOVES;

	std::vector<Piece*>* team_ptr {nullptr};
	if(_team == 1){
		team_ptr = &teamW;
	} else {
		team_ptr = &teamB;
	}

	for(size_t i = 0; i < team_ptr->size(); i++){
		int temp_coord1 = team_ptr->at(i)->get_coord();
		if(temp_coord1 == -2){
			continue;
		}
		std::vector<std::vector<int>> temp_piece_moves = display_moves(temp_coord1, _team, "coord1");
		display_moves(temp_coord1, _team, "coord2");
		for(size_t j = 0; j < temp_piece_moves.size(); j++){
			int temp_coord2 = temp_coord1 + (temp_piece_moves.at(j).at(0) + (8*(temp_piece_moves.at(j).at(1))));
			ALL_MOVES.push_back(std::vector<int>{temp_coord1, temp_coord2});
		}	
	}
	return ALL_MOVES;
}

std::pair<int, std::vector<int>> minimax(int _team, int _depth, std::vector<int> &move_vec){

	// check if other team is checkmated
	bool cmate {is_checkmate(_team)};
	if(_depth == 0 || cmate){
		int bonus {0};
		if(cmate){
			bonus += (10000*_team*-1);
		}
		std::pair<int, std::vector<int>> leaf = std::make_pair(get_board_value() + bonus, move_vec);
		return leaf;
	} else {
		int inf = (_team == 1) ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
		
		std::pair<int, std::vector<int>> current_best = std::make_pair(inf, std::vector<int>{0,0});

		std::vector<std::vector<int>> all_moves_vec = all_moves(_team);
		
		for(size_t i = 0; i < all_moves_vec.size(); i++){
			int coord1 = all_moves_vec.at(i).at(0);
			int coord2 = all_moves_vec.at(i).at(1);

			// std::cerr << coord1 << " " << coord2 << "\n";

			// create a copy of the team vector to be reset later
			// std::vector<Piece*> teamW_copy = teamW;
			// std::vector<Piece*> teamB_copy = teamB;

			Piece* temp_enemy = main_board.at(coord2).get_tenant();
			move(coord1, coord2, _team);

			// team_vector_cleaner(teamW);
			// team_vector_cleaner(teamB);

			// std::cerr << "TEAM WHITE\n";
			// for(size_t i = 0; i < teamW.size(); i++){
			// 	std::cerr << teamW.at(i)->get_coord() << " ";
			// }
			// std::cerr << "\n";
			// std::cerr << "TEAM BLACK\n";
			// for(size_t i = 0; i < teamB.size(); i++){
			// 	std::cerr << teamB.at(i)->get_coord() << " ";
			// }
			// std::cerr << "\n\n";

			std::pair<int, std::vector<int>> value = minimax(_team*-1, _depth-1, all_moves_vec.at(i));
			
			if(_team == 1 && std::get<int>(value) > std::get<int>(current_best)){
				current_best = value;
			} else if(_team == -1 && std::get<int>(value) < std::get<int>(current_best)){
				current_best = value;
			}

			move(coord2, coord1, _team); // move piece back
			main_board.at(coord2).set_tenant(temp_enemy);

			// teamW = teamW_copy;
			// teamB = teamB_copy;
		}
		return current_best;
	}
	
}



#endif