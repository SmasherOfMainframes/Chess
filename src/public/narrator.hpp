#ifndef __NARRATOR__
#define __NARRATOR__

extern std::string TEAMW_NAME;
extern std::string TEAMB_NAME;


void title(){
	std::cout << GAME_COL << "                   ~ CHESS ~\n";
}


int narrator(){
	std::string coordinate1;
	std::string coordinate2;
	int int_coord1;
	int int_coord2;

	static int turn {1};
	static std::string error_message {""};
	static std::string check_message {""};
	static std::string phase;

	team_vector_cleaner(teamW);
	team_vector_cleaner(teamB);

	if(
		turn == 1 && check_vec_w.size() > 0 
		||
		turn == -1 && check_vec_b.size() > 0
		) {
		check_checkmate(turn);
	}

	// --- PHASE 1 --- ///
	phase = "coord1";

	if(check_message.size()>0){
		std::cout << check_message << std::endl;
	}
	if(error_message.size()>1){
		std::cout << error_message << std::endl;
	}

	std::string active = (turn == 1) ? TEAMW_NAME : TEAMB_NAME ;
	std::cout << active << "'s turn." << std::endl;

	std::cout << "Enter coordinate of piece to move : ";
	std::cin >> coordinate1;

	// Checks validity of user input, if no errors, returns 0
	int error_code = check_coord1(coordinate1, turn, phase);

	if(error_code){
		error_code_message(error_code, error_message);
		return 0; // break and restart
	}

	int_coord1 = coord_conversion(coordinate1);

	// Updates the board to show possible moves after the next screen clear
	display_moves(int_coord1, turn, phase);
	



	// --- PHASE 2 --- //
	phase = "coord2";

	system("clear");
	title();
	draw_board();
	
	std::cout << "Enter coordinate of target : ";
	std::cin >> coordinate2;

	error_code = check_coord2(coordinate2, turn, phase);

	// Clears the board of all possible moves after next screen clear
	display_moves(int_coord1, turn, phase);
	
	if(error_code){
		error_code_message(error_code, error_message);
		return 0;
	}

	int_coord2 = coord_conversion(coordinate2);

	// Need to store any potential enemy piece at coordinate 2
	// in a temporary variable, to prevent piece from remaining 
	// captured after the move is possibly reverted in next step.
	Piece* temp_piece {nullptr};
	if(main_board.at(int_coord2).get_tenant_team() != -2){
		temp_piece = main_board.at(int_coord2).get_tenant();
	}
	move(int_coord1, int_coord2, turn);

	// Check if moving the piece caused your king to enter Check
	// If so, undo() the last move and put any captured piece back
	if(king_check(turn, error_message)){
		move(int_coord2, int_coord1, turn); // undo the move
		main_board.at(int_coord2).set_tenant(temp_piece); // puts the piece back
		return 0;
	}
	
	
	// Special pawn things
	if(main_board.at(int_coord2).get_tenant_rank() == 1){
		if(main_board.at(int_coord2).get_tenant_first_move() == true){
			main_board.at(int_coord2).set_tenant_first_move(false);
		}

		if((turn == 1 && int_coord2 > 55) || (turn == -1 && int_coord2 < 8)){
			char new_rank;
			bool pp_bool{true};
			while(pp_bool){
				std::cout << "Promote pawn to symbol : " ;
				std::cin >> new_rank;
				if(main_board.at(int_coord2).tenant_pawn_promotion(new_rank)){
					pp_bool = false;
				} else {
					std::cout << "Not a valid symbol." << std::endl;
				}
			}
		}
	}

	// Check if moving the piece causes enemy to enter Check
	if(king_check(turn*-1, error_message)){
		if(turn == 1){
			check_message = TEAMB_NAME + " in check!\n";
		} else {
			check_message = TEAMW_NAME + " in check!\n";
		}
	} else {
		check_message = "";
	}


	turn*=-1;

	error_message = "";
	
	
	return 0;
}

#endif