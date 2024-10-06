#include "keeper.h"

void Keeper::resize() {
	int newcpct = (cpct == 0) ? 1 : cpct * 2;
	Garage** newvehicles = new Garage * [newcpct];

	for (int i = 0; i < size; ++i)
		newvehicles[i] = vehicles[i];

	delete[] vehicles;
	vehicles = newvehicles;
	cpct = newcpct;
}

Keeper::~Keeper() {
	for (int i = 0; i < size; ++i)
		delete vehicles[i];
	delete[] vehicles;
}

void Keeper::add(Garage* vehicle) {
	if (size == cpct)
		resize();

	vehicles[size++] = vehicle;
}

void Keeper::printall() const {
	for (int i = 0; i < size; ++i) {
		cout << i + 1 << ": ";
		vehicles[i]->print();
	}
}

