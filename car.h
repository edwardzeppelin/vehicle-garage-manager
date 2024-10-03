#ifndef CAR_H
#define CAR_H

#include "garage.h"

class Car : public Garage
{
private:
	float enginev;
	string colour;
	string gearbox;
public:
	Car(string brand, string model, float enginev, string colour, string gearbox) : Garage(brand, model)
	{
		this->enginev = enginev;
		this->colour = colour;
		this->gearbox = gearbox;
	}
};

#endif