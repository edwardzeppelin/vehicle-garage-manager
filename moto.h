#ifndef MOTO_H
#define MOTO_H

#include "garage.h"

class Motorcycle : public Garage
{
private:
	float enginev;
	int horsepwr;
	string typeofterrain;
public:
	Motorcycle(string brand, string model, float enginev, int horsepwr, string typeofterrain) : Garage(brand, model)
	{
		this->enginev = enginev;
		this->horsepwr = horsepwr;
		this->typeofterrain = typeofterrain;
	}
};

#endif