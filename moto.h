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
	Motorcycle(string brand, string model, float enginev, int horsepwr, string terrain) : brand(brand), model(model), enginev(enginev), horsepwr(horsepwr), terrain(terrain) { cout << "Motorcycle parametrized constructor called" << endl; };
	Motorcycle(const Motorcycle& other);
	Motorcycle() { cout << "Motorcycle default constructor called" << endl;  };
	~Motorcycle() { cout << "Motorcycle deconstructor called" << endl; };

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
	void getveh();
	string gettype() const override { return "Moto"; }
	void print() const override;
	void serialize(ofstream& out) const override;
	void deserialize(ifstream& in) override;

};

#endif