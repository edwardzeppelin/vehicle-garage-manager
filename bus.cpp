#include "bus.h"

Bus::Bus(string brand, string model, int sitseats, int allseats, string destination) {
	this->brand = brand;
	this->model = model;
	this->sitseats = sitseats;
	this->allseats = allseats;
	this->destination = destination;
}

void Bus::print() const {
	cout << "Bus: " << brand << " " << model << " " << sitseats << " " << allseats << " " << destination << endl;
}