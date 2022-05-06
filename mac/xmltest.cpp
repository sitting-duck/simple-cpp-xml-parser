#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;
int gPass = 0;
int gFail = 0;

int main( int argc, const char ** argv ) {
    std::cout << "hello world" << std::endl;
    if ( argc > 1 ) {
    	XMLDocument* doc = new XMLDocument();
    	XMLError err = doc->LoadFile( argv[1] );
    }
	if(err == XML_SUCCESS) {
		std::cout << "file loaded successfully!" << std::endl; 
	} 
    return 1;
}

