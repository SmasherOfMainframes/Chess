#ifndef __PAWN_MS__
#define __PAWN_MS__


void pawn_moves(std::vector<std::vector<int>> &_vec, int &_team, int _coord){
	
	// check if a team or enemy piece is blocking one tile ahead
	if(
		!team_obstruction(_coord + (8*_team), _team)
	  	&&
	  	!enmy_obstruction(_coord + (8*_team), _team)
	  	) {
		_vec.push_back(std::vector<int>{0, _team*1});
		
		// check if a team piece is blocking two tiles ahead
		if(
			(
				!team_obstruction(_coord + (16*_team), _team)
		   		&&
		   		!enmy_obstruction(_coord + (16*_team), _team)
			)
			&&
			(
				main_board.at(_coord).get_tenant_first_move()
			)

			) {
				_vec.push_back(std::vector<int>{_team*0, _team*2});
			}
		}
	
	// Checking if the pawn can capture a diagonal enemy
	if(
		main_board.at(_coord + (9 * _team)).get_tenant_team() == _team*-1
		&&
		(_coord+1) % 8 != 0
		) {
		_vec.push_back(std::vector<int>{_team*1, _team*1});
	}
	if(
		main_board.at(_coord + (7 * _team)).get_tenant_team() == _team*-1
		&&
		_coord % 8 != 0
		) {
		_vec.push_back(std::vector<int>{_team*-1, _team*1});
	}
				
}




#endif