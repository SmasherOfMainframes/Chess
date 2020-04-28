#ifndef __ROOK_MS__
#define __ROOK_MS__


void rook_moves(std::vector<std::vector<int>> &_vec, int &_team, int _coord){
	// team hit works
	// enmy
	// direct edge
	// (>1) edge works
	for(int i = 0; i < (7-(_coord%8)); i++){
		if(team_obstruction(_coord+1+i, _team)){break;}
		_vec.push_back(std::vector<int>{i+1, 0});
		if(enmy_obstruction(_coord+1+i, _team)){break;}
	}
	// team hit works
	// enmy hit works
	// dir edge works
	// (>1) edge works
	for(int i = 0; i < _coord%8 ; i++){
		if(team_obstruction(_coord-1-i, _team)){break;}
		_vec.push_back(std::vector<int>{(-1*i)-1, 0});
		if(enmy_obstruction(_coord-1-i, _team)){break;}
	}

	// team hit works
	// enmy
	// dir edge works
	// (>1) edge works
	for(int i = 0; i < 8-((_coord/8)+1); i++){
		if(team_obstruction(_coord+8+(8*i), _team)){break;}
		_vec.push_back(std::vector<int>{0, i+1});
		if(enmy_obstruction(_coord+8+(8*i), _team)){break;}
	}
	// team hit works
	// enmy
	// dir edge works
	// (>1) edge
	for(int i = 0; i < (_coord/8); i++){
		if(team_obstruction(_coord-8-(8*i), _team)){break;}
		_vec.push_back(std::vector<int>{0, (-1*i)-1});
		if(enmy_obstruction(_coord-8-(8*i), _team)){break;}
	}
}


#endif