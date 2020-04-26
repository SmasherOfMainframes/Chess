#ifndef __SETUP_FNS__
#define __SETUP_FNS__

// regular setup

void initialize_regular(){
	Piece* temp = new Piece(1, 'p', 0);
	main_board.at(0).set_tenant(temp);
}




#endif