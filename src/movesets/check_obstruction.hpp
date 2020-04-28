#ifndef __CHECK_OBSTRUCT__
#define __CHECK_OBSTRUCT__

bool team_obstruction(int _coord, int _team){
	if(main_board.at(_coord).get_tenant_team() == _team){
		return(true);
	} else {
		return(false);
	}
}
bool enmy_obstruction(int _coord, int _team){
	if(main_board.at(_coord).get_tenant_team() == _team*-1){
		return(true);
	} else {
		return(false);
	}
}



#endif