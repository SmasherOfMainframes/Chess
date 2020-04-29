#ifndef __KNIGHT_MS__
#define __KNIGHT_MS__


void kngt_moves(std::vector<std::vector<int>> &_vec, int &_team, int _coord){
	std::cerr << "KNIGHT SELECTED\n";

	for(int x = -2; x < 3; x++){
		std::cerr << "BEGIN X LOOP\n";
		std::cerr << "X: " << x << "\n";
		// x = -2, -1, 1, 2
		if(x!=0){
			
			std::cerr << "X NOT ZERO IS TRUE\n";

			for(int y = -2; y < 3; y++){
				std::cerr << "BEGIN Y LOOP\n";
				std::cerr << "Y: " << y << "\n";
				// y = -2, -1, 1, 2
				if(y!=0 && abs(x)!=abs(y)){
					
					std::cerr << "Y NOT ZERO and X!=Y IS TRUE\n";
					// (x,y) = ()
					if(
						!check_wrap(_coord, x)
						&&
						!check_ends(_coord, y)
						&&
						!team_obstruction(_coord + x + (8*y), _team)
						) {
						std::cerr << "PUSH BACK BEGIN\n";
						_vec.push_back(std::vector<int>{x, y});
						std::cerr << "PUSH BACK COMPLETE\n";
					}
				}
			}
		}
	}
}




#endif