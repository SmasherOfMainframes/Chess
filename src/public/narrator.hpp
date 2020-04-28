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
	std::cout << GAME_COL << "                   ~ CHESS ~\n" << std::endl;
}

int narrator(){
	std::string coordinate1;
	std::string coordinate2;
	static int turn {1};
	static std::string error_message {""};
	static std::string phase;

	// --- PHASE 1 --- ///
	phase = "coord1";

	if(error_message.size()>1){
		std::cout << error_message << std::endl;
	}

	std::string active = (turn == 1) ? TEAMW_NAME : TEAMB_NAME ;
	std::cout << active << "'s turn." << std::endl;

	std::cout << "Enter coordinate of piece to move : ";
	std::cin >> coordinate1;

	// Checks validity of user input, if no errors, returns 0
	int error_code = check_coord1(coordinate1, turn, phase);
	//turn this into a function
	if(error_code){
		error_code_message(error_code, error_message);
		return 0; // break and restart
	}

	// Updates the board to show possible moves after the next screen clear
	display_moves(coord_conversion(coordinate1), turn, phase);
	
	// --- PHASE 2 --- //
	phase = "coord2";

	system("clear");
	title();
	draw_board();
	
	std::cout << "Enter coordinate of target : ";
	std::cin >> coordinate2;

	error_code = check_coord2(coordinate2, turn, phase);

	// Clears the board of all possible moves after next screen clear
	display_moves(coord_conversion(coordinate1), turn, phase);
	
	if(error_code){
		error_code_message(error_code, error_message);
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