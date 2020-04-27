#ifndef __NARRATOR__
#define __NARRATOR__

#include <string>

void title(){
	std::cout << "           ~ CHESS ~\n" << std::endl;
}

void move(int _i, int _f){
	// 9 17
	main_board.at(_i).move_tenant(main_board.at(_f));
}

int check_coord1(std::string _coord, int _turn){
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

	int team_number {main_board.at(coord_conversion(_coord)).get_tenant_team()};
	if(team_number != _turn){
		if(team_number == -2){
			return 2;
		}
		return 3;
	}
	return 0;
}

int narrator(){
	std::string coordinate1;
	std::string coordinate2;
	static int turn {-1};
	static std::string error_message {""};

	if(error_message.size()>1){
		std::cout << error_message << std::endl;
	}

	std::string active = (turn == 1) ? "Cyan's " : "Purple's " ;
	std::cout << active << "turn." << std::endl;

	std::cout << "Enter coordinate of piece to move : ";
	std::cin >> coordinate1;

	// Checks validity of user input
	int error_code = check_coord1(coordinate1, turn);
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

	std::cout << "Enter coordinate of target : ";
	std::cin >> coordinate2;

	move(coord_conversion(coordinate1), coord_conversion(coordinate2));
	turn*=-1;

	error_message = "";
	return 0;
}

#endif