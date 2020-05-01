#ifndef __CHECK_EDGES__
#define __CHECK_EDGES__


bool wrapping_x(int _coord, int x_inc){
	if( 
		(_coord / 8) != ((_coord + x_inc) / 8)
		||
		_coord + x_inc < 0 // when _coord is A1 or A2
		
		 ){
		return(true);
	} else {
		return(false);
	}
}

bool out_bounds_y(int _coord, int y_inc){
	if( (_coord + (8 * y_inc)) > 63 || (_coord + (8 * y_inc)) < 0 ){
		return(true);
	} else {
		return(false);
	}
}




#endif