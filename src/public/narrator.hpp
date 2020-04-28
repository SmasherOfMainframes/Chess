#ifndef __NARRATOR__
#define __NARRATOR__

// // move_list_fns.hpp prototypes
// void pawn_move_list(std::vector<std::vector<int>>);

// void check_obstruction_pawn(int _coord, std::vector<std::vector<int>> _move_vec, int _team){ 
// 	if(main_board.at(_coord + (8*_team)).get_tenant_team() != -2){
// 		_move_vec.at(0).at(1) = 0;
// 	}
// }

void title(){
	std::cout << "                   ~ CHESS ~\n" << std::endl;
}

// literally just a shortcut for moving pieces
void move(int _initial, int _final){
	// 9 17
	main_board.at(_initial).move_tenant(main_board.at(_final));
}

// checks validity of user input for coordinate 1
int check_coord1(std::string _coord, int _turn, std::string _phase){
	if(_coord == "exit"){
		exit(0);
	}
	if(_coord.size() > 2){
		return 1;
	}
	if(!(
		((_coord[0] >= '0' && _coord[0] <= '8') && (toupper(_coord[1]) >= 'A' && toupper(_coord[1]) <= 'H'))
		|| 
		((_coord[1] >= '0' && _coord[1] <= '8') && (toupper(_coord[0]) >= 'A' && toupper(_coord[0]) <= 'H'))
	  )) {
		return 1;
	} // makes sure string is one int and one alpha char
	
	// at this point the input is safe to put into coord_conversion()
	if(_phase == "coord1"){
		int team_number {main_board.at(coord_conversion(_coord)).get_tenant_team()};
		if(team_number != _turn){
			if(team_number == -2){
				return 2;
		}
		return 3;
		}
	}
	
	return 0;
}

int check_coord2(std::string _coord, int _turn, std::string _phase){
	// if "back"
	int check_coord1_val = check_coord1(_coord, _turn, _phase);
	if(check_coord1_val){
		return check_coord1_val;
	}

	if(main_board.at(coord_conversion(_coord)).get_charset() != MOVES_TILE_CHAR){
		return 5;
	}
	return 0;
}

void display_moves(int _coord, int _turn, std::string _phase){
	static std::vector<std::vector<int>> move_vec;
	if(_phase == "coord1"){
		move_vec.clear();

		int temp_team = main_board.at(_coord).get_tenant_team();

		// PAWN
		if(main_board.at(_coord).get_tenant_rank() == 1){
			
			// because the pawn is sooooo special we have to do lots of extra work
			std::cerr << "Entering the danger zone" << std::endl;
			pawn_move_list(move_vec);
			
			// makes black pawns moveset move down, rather than up
			if(temp_team == -1){
				for(size_t i = 0; i < move_vec.size(); i++){
					move_vec.at(i).at(1) *= -1; 
				}
			}
			
			// Checking if the pawn can capture a diagonal enemy
			if(main_board.at(_coord + (9 * temp_team)).get_tenant_team() == temp_team*-1){
				move_vec.push_back(std::vector<int>{temp_team*1, temp_team*1});
			}
			if(main_board.at(_coord + (7 * temp_team)).get_tenant_team() == temp_team*-1){
				move_vec.push_back(std::vector<int>{temp_team*-1, temp_team*1});
			}
			
			if(main_board.at(_coord).get_tenant_first_move()){
				move_vec.push_back(std::vector<int>{temp_team*0, temp_team*2});
			}

			// Check for obstructions
			// check_obstruction_pawn(_coord, move_vec, temp_team);
				
		}

		// set temporary unique charset for selected piece
		main_board.at(_coord).set_charset(SELF_TILE_CHAR);
		main_board.at(_coord).set_charset_color(MOVES_TILE_COL);

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

int narrator(){
	std::string coordinate1;
	std::string coordinate2;
	static int turn {1};
	static std::string error_message {""};
	static std::string phase;

	phase = "coord1";

	if(error_message.size()>1){
		std::cout << error_message << std::endl;
	}

	std::string active = (turn == 1) ? "Cyan's " : "Purple's " ;
	std::cout << active << "turn." << std::endl;

	std::cout << "Enter coordinate of piece to move : ";
	std::cin >> coordinate1;

	// Checks validity of user input
	int error_code = check_coord1(coordinate1, turn, phase);
	//turn this into a function
	if(error_code){
		if(error_code==1){
			error_message = "Invalid coordinate.";	
		} else if(error_code == 2){
			error_message = "No piece there!";
		} else if(error_code == 3){
			error_message = "Not your piece!";
		}
		return 0;
	}

	display_moves(coord_conversion(coordinate1), turn, phase);
	phase = "coord2";

	system("clear");
	title();
	draw_board();
	
	std::cout << "Enter coordinate of target : ";
	std::cin >> coordinate2;

	error_code = check_coord2(coordinate2, turn, phase);

	display_moves(coord_conversion(coordinate1), turn, phase);
	
	if(error_code){
		if(error_code==1){
			error_message = "Invalid coordinate.";	
		} else if(error_code == 2){
			error_message = "No piece there!";
		} else if(error_code == 3){
			error_message = "Not your piece!";
		} else if(error_code == 5){
			error_message = "Not a valid move!";
		}
		return 0;
	}

	if(
		main_board.at(coord_conversion(coordinate1)).get_tenant_rank() == 1
	    &&
	    main_board.at(coord_conversion(coordinate1)).get_tenant_first_move() == true
	    ) {
		
		main_board.at(coord_conversion(coordinate1)).set_tenant_first_move(false);
	}

	move(coord_conversion(coordinate1), coord_conversion(coordinate2));
	turn*=-1;

	error_message = "";
	
	return 0;
}

#endif