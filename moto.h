#ifndef MOTO_H
#define MOTO_H

#include "garage.h"

class Motorcycle : public Garage
{
private:
	string brand;
	string model;
	float enginev;
	int horsepwr;
	string terrain;
public:
	Motorcycle(string brand, string model, float enginev, int horsepwr, string terrain);

	void setbrand(const string& newbrand) { brand = newbrand; };
	void setmodel(const string& newmodel) { model = newmodel; };
	void setenginev(const float& newenginev) { enginev = newenginev; };
	void sethorsepwr(const int& newhorsepwr) { horsepwr = newhorsepwr; };
	void setgearbox(const string& newgearbox) { terrain = newgearbox; };

	void print() const override;

};

#endif