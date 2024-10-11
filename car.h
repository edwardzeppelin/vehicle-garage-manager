#ifndef CAR_H
#define CAR_H

#include "garage.h"
#include <fstream>

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
	Car() {};

	void setbrand(const string& newbrand) { brand = newbrand; };
	void setmodel(const string& newmodel) { model = newmodel; };
	void setenginev(const float& newenginev) { enginev = newenginev; };
	void setcolour(const string& newcolour) { colour = newcolour; };
	void setgearbox(const string& newgearbox) { gearbox = newgearbox; };

	void sethorsepwr(const int& newhorsepwr) override {}
	void setterrain(const string& newterrain) override {}
	void setsitseats(const int& newsitseats) override {}
	void setallseats(const int& newallseats) override {}
	void setdestination(const string& newdestination) override {}

	void getveh() {
		cout << brand << " " << model << " " << enginev << " " << colour << " " << gearbox << endl;
	}

	void print() const override;

	string gettype() const override{
		return "Car";
	}


	/*
	friend std::ostream& operator<<(std::ostream& os, const Car& car) {
		os << "Car " << car.brand << " " << car.model << " " << car.enginev << " " << car.colour << " " << car.gearbox << "\n";
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Car& car) {
		is >> car.brand >> car.model >> car.enginev >> car.colour >> car.gearbox;
		return is;
	}*/

	void serialize(std::ofstream& out) const override {
		out << "Car: " << brand << " " << model << " " << enginev << " " << colour << " " << gearbox << "\n";
	}

	void deserialize(std::ifstream& in) override {
		std::string type;
		in >> type >> brand >> model >> enginev >> colour >> gearbox;
	}

};

#endif