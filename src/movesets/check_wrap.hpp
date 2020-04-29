#ifndef __CHECK_EDGES__
#define __CHECK_EDGES__


bool check_wrap(int _coord, int x_inc){
	std::cerr << "CHECK WRAP BEGIN\n";
	if( 
		(_coord / 8) != ((_coord + x_inc) / 8)
		||
		_coord + x_inc < 0
		
		 ){
		std::cerr << "CHECK WRAP TRUE\n";
		return(true);
	} else {
		std::cerr << "CHECK WRAP FALSE\n";
		return(false);
	}
}

bool check_ends(int _coord, int y_inc){
	std::cerr << "CHECK ENDS BEGIN\n";
	if( (_coord + (8 * y_inc)) > 63 || (_coord + (8 * y_inc)) < 0 ){
		std::cerr << "CHECK ENDS TRUE\n";
		return(true);
	} else {
		std::cerr << "CHECK ENDS FALSE\n";
		return(false);
	}
}




#endif