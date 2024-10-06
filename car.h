#ifndef CAR_H
#define CAR_H

#include "garage.h"

class Car : public Garage
{
private:
	string brand;
	string model;
	float enginev;
	string colour;
	string gearbox;

public:
	Car(string brand, string model, float enginev, string colour, string gearbox);

	void setbrand(const string& newbrand) { brand = newbrand; };
	void setmodel(const string& newmodel) { model = newmodel; };
	void setenginev(const float& newenginev) { enginev = newenginev; };
	void setcolour(const string& newcolour) { colour = newcolour; };
	void setgearbox(const string& newgearbox) { gearbox = newgearbox; };

	void print() const override;

};

#endif