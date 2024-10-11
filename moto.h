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
	void setterrain(const string& newterrain) { terrain = newterrain; };

	void setcolour(const string& newcolour) override {}
	void setgearbox(const string& newgearbox) override {}
	void setsitseats(const int& newsitseats) override {}
	void setallseats(const int& newallseats) override {}
	void setdestination(const string& newdestination) override {}

	void getveh() {
		cout << brand << " " << model << " " << enginev << " " << horsepwr << " " << terrain << endl;
	}

	string gettype() const override {
		return "Moto";
	}

	void print() const override;

};

#endif