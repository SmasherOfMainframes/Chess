#ifndef __SETUP_FNS__
#define __SETUP_FNS__

// regular setup

std::vector<Piece*> team0 {
	new Piece(1, 'p', 0),
	new Piece(1, 'p', 0),
	new Piece(1, 'p', 0),
	new Piece(1, 'p', 0),
	new Piece(1, 'p', 0),
	new Piece(1, 'p', 0),
	new Piece(1, 'p', 0),
	new Piece(1, 'p', 0),
	new Piece(2, 'R', 0),
	new Piece(3, 'K', 0),
	new Piece(4, 'B', 0),
	new Piece(5, 'Q', 0),
	new Piece(6, '$', 0),
	new Piece(4, 'B', 0),
	new Piece(3, 'K', 0),
	new Piece(2, 'R', 0)
};
std::vector<Piece*> team1 {
	new Piece(2, 'R', 1),
	new Piece(3, 'K', 1),
	new Piece(4, 'B', 1),
	new Piece(6, '$', 1),
	new Piece(5, 'Q', 1),
	new Piece(4, 'B', 1),
	new Piece(3, 'K', 1),
	new Piece(2, 'R', 1),
	new Piece(1, 'p', 1),
	new Piece(1, 'p', 1),
	new Piece(1, 'p', 1),
	new Piece(1, 'p', 1),
	new Piece(1, 'p', 1),
	new Piece(1, 'p', 1),
	new Piece(1, 'p', 1),
	new Piece(1, 'p', 1),
};

void initialize_regular(){
	for(int i = 0; i < 16; i++){
		main_board.at(i).set_tenant(team1.at(i));
	}
	for(int i = 48; i < 64; i++){
		main_board.at(i).set_tenant(team0.at(i-48));
	}
}




#endif