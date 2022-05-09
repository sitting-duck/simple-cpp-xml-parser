
#include <string>

class Location {

public: 
	inline Location()
	{
		name = std::string("");
		id = std::string("");
		lat = std::string("");
		lon = std::string("");
		nodeType = std::string("");
	}
	
	inline Location(std::string name, std::string id, std::string lat, std::string lon, std::string nodeType) {
		this->name = name;
		this->id = id;
		this->lat = lat;
		this->lon = lon;
		this->nodeType = nodeType;
	}

	inline ~Location() {}

	inline std::string getName() { return this->name; }

	inline std::string getId() { return this->id; }

	inline std::string getLat() { return this->lat; }

	inline std::string getLon() { return this->lon; }

private:
	std::string name;
	std::string id;
	std::string lat;
	std::string lon;
	std::string nodeType;

};

