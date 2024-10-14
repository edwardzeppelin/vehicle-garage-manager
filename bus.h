#ifndef BUS_H
#define BUS_H

#include "garage.h"

class Bus : public Garage
{
private:
	string brand;
	string model;
	int sitseats;
	int allseats;
	string destination;

public:
	Bus(string brand, string model, int sitseats, int allseats, string destination) : brand(brand), model(model), sitseats(sitseats), allseats(allseats), destination(destination) { cout << "Bus parametrized constructor called" << endl; };
	Bus(const Bus& other);
	Bus() { cout << "Bus default constructor called" << endl; };
	~Bus() { cout << "Bus deconstructor called" << endl; };

	void setbrand(const string& newbrand) { brand = newbrand; };
	void setmodel(const string& newmodel) { model = newmodel; };
	void setsitseats(const int& newsitseats) { sitseats = newsitseats; };
	void setallseats(const int& newallseats) override { allseats = newallseats; };
	void setdestination(const string& newdestination) { destination = newdestination; };
	void sethorsepwr(const int& newhorsepwr) override {}
	void setterrain(const string& newterrain) override {}
	void setenginev(const float& newenginev) override {}
	void setcolour(const string& newcolour) override {}
	void setgearbox(const string& newgearbox) override {}
	void getveh();
	string gettype() const override { return "Bus"; }
	void print() const override;
	void serialize(ofstream& out) const override;
	void deserialize(ifstream& in) override;

};

#endif