#include "car.h"

Car::Car(string brand, string model, float enginev, string colour, string gearbox) {
	this->brand = brand;
	this->model = model;
	this->enginev = enginev;
	this->colour = colour;
	this->gearbox = gearbox;
}

void Car::print() const {
	cout << "Car: " << brand << " " << model << " " << colour << " " << enginev << " " << gearbox << endl;
}