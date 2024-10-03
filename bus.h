#ifndef BUS_H
#define BUS_H

#include "garage.h"

class Bus : public Garage
{
private:
	int sitseats;
	int allseats;
	string destination;
public:
	Bus(string brand, string model, int sitseats, int allseats, string destination) : Garage(brand, model)
	{
		this->sitseats = sitseats;
		this->allseats = allseats;
		this->destination = destination;
	}
};

#endif