#ifndef __COORD_CONVERSION__
#define __COORD_CONVERSION__

#include <cstring>

// INPUT --> SPLIT --------------> (X, Y) ---> (x + 8*y) = FINAL 
// A1 -----> char 'A' | int 1 ---> (0, 0) ---> (0 + 8*0) = 0
// C4 -----> char 'C' | int 4 ---> (2, 3) ---> (2 + 8*3) = 26
// H8 -----> char 'H' | int 8 ---> (7, 7) ---> (7 + 8*7) = 63

int coord_conversion(std::string _s){
	int y_int;
	int x_int;

	if(_s[0] >= 48 && _s[0] <= 57){ 	// _s[0] is the int
		// since _s[0] gives an ascii value, subtract ascii of 0 to get actual int value
		// subtract 1 to avoid off by one error
		y_int = _s[0] - '0' - 1;
		// subtract ascii value of 'A' (65) from the uppercase version of the character
		// coordinate to convert character into an int value.
		x_int = toupper(_s[1]) - 'A';
	} else { 							// _s[1] is the int
		y_int = _s[1] - '0' - 1;
		x_int = toupper(_s[0]) - 'A';
	}
	return(x_int + 8*y_int);
}

// testing
// int test1 = coord_conversion("A1");
// int test11 = coord_conversion("1A");
// int test2 = coord_conversion("C4");
// int test22 = coord_conversion("4c");
// int test3 = coord_conversion("H8");
// std::cout << test1 << " " << test2 << " " << test3 << " " << std::endl; 



#endif