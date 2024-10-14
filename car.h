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
	Car(string brand, string model, float enginev, string colour, string gearbox) : brand(brand), model(model), enginev(enginev), colour(colour), gearbox(gearbox) { cout << "Car parametrized constructor called" << endl; };
	Car(const Car& other);
	Car() { cout << "Car default constructor called" << endl; };
	~Car() { cout << "Car deconstructor called" << endl; };

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
	void getveh();
	void print() const override;
	string gettype() const override{ return "Car";}
	void serialize(ofstream& out) const override;
	void deserialize(ifstream& in) override;

};

#endif