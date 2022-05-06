// _MSC_VER Defined as an integer literal that encodes the major and minor number 
//elements of the compiler's version number. The major number is the first element 
//of the period-delimited version number and the minor number is the second element.
// For example, if the version number of the Microsoft C/C++ compiler is 
//17.00.51106.1, the _MSC_VER macro evaluates to 1700. Enter cl /? at the command 
//line to view the compiler's version number. This macro is always defined.

#if defined( _MSC_VER )
	#if !defined( _CRT_SECURE_NO_WARNINGS )
		#define _CRT_SECURE_NO_WARNINGS		// This test file is not intended to be secure.
	#endif
#endif

#include <iostream>

int main() {
    std::cout << "hello world" << std::endl;
    return 1;
}

