#ifndef __COORD_CHECKERS__
#define __COORD_CHECKERS__

// checks validity of user input for coordinate 1
int check_coord1(std::string _coord, int _turn, std::string _phase){
	if(_coord == "exit"){
		exit(0);
	}
	if(_coord.size() > 2){
		return 101;
	}
	if(!(
		((_coord[0] >= '0' && _coord[0] <= '8') && (toupper(_coord[1]) >= 'A' && toupper(_coord[1]) <= 'H'))
		|| 
		((_coord[1] >= '0' && _coord[1] <= '8') && (toupper(_coord[0]) >= 'A' && toupper(_coord[0]) <= 'H'))
	  )) {
		return 101;
	} // makes sure string is one int and one alpha char
	
	// at this point the input is safe to put into coord_conversion()
	if(_phase == "coord1"){
		int team_number {main_board.at(coord_conversion(_coord)).get_tenant_team()};
		if(team_number != _turn){
			if(team_number == -2){
				return 102;
		}
		return 103;
		}
	}
	
	return 0;
}

int check_coord2(std::string _coord, int _turn, std::string _phase){
	if(_coord == "back"){
		return 105;
	}
	int check_coord1_val = check_coord1(_coord, _turn, _phase);
	if(check_coord1_val){
		return check_coord1_val;
	}

	if(main_board.at(coord_conversion(_coord)).get_charset() != MOVES_TILE_CHAR){
		return 106;
	}
	return 0;
}

int error_code_message(int _ecode, std::string &_emessage){
	if(_ecode == 101){
		_emessage = "Invalid coordinate.";	
	} else if(_ecode == 102){
		_emessage = "No piece there!";
	} else if(_ecode == 103){
		_emessage = "Not your piece!";
	} else if(_ecode == 105){
		_emessage = "";
	} else if(_ecode == 106){
		_emessage = "Not a valid move!";
	}
	return 0;
}



#endif