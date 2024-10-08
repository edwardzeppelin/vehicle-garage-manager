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
	Bus(string brand, string model, int sitseats, int allseats, string destination);

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

	string gettype() const override {
		return "Bus";
	}

	/*
	string getbrand() const { return brand; };
	string getmodel() const { return model; };
	int getsitseats() const { return sitseats; };
	int getallseats() const { return allseats; };
	string getdestination() const { return destination; };

	friend ostream& operator<<(ostream& os, const Bus& bus) {
		os << "Bus: " << bus.brand << " " << bus.model << " " << bus.sitseats << " " << bus.allseats << " " << bus.destination;
		return os;
	}
	*/

	void print() const override;

};

#endif