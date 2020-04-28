#ifndef __QUEEN_MS__
#define __QUEEN_MS__


void quen_moves(std::vector<std::vector<int>> &_vec, int &_team, int _coord){
	rook_moves(_vec, _team, _coord);
	bshp_moves(_vec, _team, _coord);
}




#endif