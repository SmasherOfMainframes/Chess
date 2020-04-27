#ifndef __DRAW_FNS__
#define __DRAW_FNS__


void draw_board(){
	for(int i = 7; i >= 0; i--){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 8; k++){
				if(j == 0 || j == 2){
					main_board.at((i*8) + k).print_generic();
				} else {
					main_board.at((i*8) + k).print_unique();
				}
			}
			std::cout << std::endl;	
		}
	}
	std::cout << std::endl;
	std::cout << "------------------------" << std::endl << std::endl;
}

#endif