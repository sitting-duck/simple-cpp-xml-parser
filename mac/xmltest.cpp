/* Compiled with C++98 */

#include <iostream>
#include <fstream>
#include <vector>
#include "tinyxml2.h"
#include "location.h"

using namespace tinyxml2;
using namespace std;
int gPass = 0;
int gFail = 0;

bool DoesFileExist (const std::string& name);

int main( int argc, const char ** argv ) {

	//std::cout << "argv[1]: " << argv[1] << std::endl;
	//std::cout << "argc: " << argc << std::endl;

	XMLError err = XML_SUCCESS;
	XMLDocument* doc = NULL; 

	if(argc == 1) {
		std::cout << "Usage: xmltest <xmlFile>" << std::endl;
		return 0;
	}
	else if ( argc == 2) {
	
		if(DoesFileExist(argv[1]) == 0) {
			std::cout << "Error: file: " << argv[1] << " does not exist." << std::endl;
			return 1;
		}
    	doc = new XMLDocument();
    	err = doc->LoadFile( argv[1] );
		if(err == XML_SUCCESS) {
			std::cout << "file loaded successfully!" << std::endl; 
		} else {
			std::cout << "Error loading file: " + std::string(XMLDocument::ErrorIDToName(err)) << std::endl;
		}
    } else {
		std::cout << "Usage: xmltest <xmlFile>" << std::endl;
	}

	// File loaded or else we have exited at this point

	XMLElement* root = doc->FirstChildElement();
	std::cout << "Root: " << root->Name() << std::endl;

	std::cout << "Root::Timespan: " << root->UnsignedAttribute("Timespan") << std::endl;

	XMLElement* geoElement = root->FirstChildElement("Geo");

	if(geoElement == NULL) {
		std::cout << "No Geo element" << std::endl;
		return 1;
	}	

	
	XMLElement* locationsNode = geoElement->FirstChildElement("Locations");
	
	std::vector<Location> locations;
	XMLElement* current = locationsNode->FirstChildElement("Loc");
	if(current == NULL) {
		std::cout << "Error: Location node is NULL" << std::endl;
		return 1;
	} else {
		std::cout << "Got " << current->Name() << std::endl;
	}
	std::string name = current->Attribute("Name");
	std::string id = current->Attribute("Id");
	std::string lat = current->Attribute("Lat");
	std::string lon = current->Attribute("Lon");
	std::string nodeType = current->Attribute("NodeType");
	Location location(name, id, lat, lon, nodeType);
	locations.push_back(location);

	do {	
		current = current->NextSiblingElement("Loc");
		if(current == NULL) {
			std::cout << "got NULL for Loc node" << std::endl;
			continue;
		}
		name = current->Attribute("Name");
		std::cout << "got name: " << name << std::endl;
		id = current->Attribute("Id");
		std::cout << "got id: " << id << std::endl;
		lat = current->Attribute("Lat");
		std::cout << "got lat: " << lat << std::endl;
		lon = current->Attribute("Lon");
		std::cout << "got lon: " << lon << std::endl;
		nodeType = current->Attribute("NodeType");
		std::cout << "got nodetype: " << nodeType << std::endl;
		location = Location(name, id, lat, lon, nodeType);
		
		locations.push_back(location);
		std::cout << "got loc: " << location.getName() << std::endl;
	
	} while(current->NextSiblingElement("Loc") != NULL);

	std::cout << "got here: " << locations.size() << std::endl;


    return 1;
}

bool DoesFileExist (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}
