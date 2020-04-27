#ifndef __MOVE_LIST_FNS__
#define __MOVE_LIST_FNS__

void pawn_move_list(std::vector<std::vector<int>> &_vec){
	std::vector<int> m1 {0, 1};
	std::vector<int> m2_1 {-1, 1}; // possible capture move
	std::vector<int> m2_2 {1, 1}; // possible capture move
	std::vector<int> m3 {0, 2}; // possible for first move only
	_vec.push_back(m1);
}



#endif