#include "moto.h"

Motorcycle::Motorcycle(string brand, string model, float enginev, int horsepwr, string terrain) {
	this->brand = brand;
	this->model = model;
	this->enginev = enginev;
	this->horsepwr = horsepwr;
	this->terrain = terrain;
}

void Motorcycle::print() const {
	cout << "Motorcycle: " << brand << " " << model << " " << enginev << " " << horsepwr << " " << terrain << endl;
}
