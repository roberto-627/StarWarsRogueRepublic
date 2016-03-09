#pragma once
#include <iostream>

using namespace std;

class Units
{
public:
	string unit_name;
	int unit_hitpoints;
	int unit_value;
	int unit_popCost;
	string unit_image_address;


	Units();

	Units(string n);
	
	virtual ~Units();
};

class LandUnits : public Units {
public:
	LandUnits();

	virtual ~LandUnits();
};

class Vehicles {

};

class Support {


};

class AirUnits {


};

