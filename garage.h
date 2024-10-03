#ifndef GARAGE_H
#define GARAGE_H

#include <iostream>
using namespace std;

class Garage
{
private:
	string brand;
	string model;
public:

	Garage(string brand, string model)
	{
		this->brand = brand;
		this->model = model;
	}

	string getbrand() const { return brand; }
	string getmodel() const { return model; }
};



#endif