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

void Keeper::deletevehicle(int index) {
	if (index < 0 || index >= size) {
		throw out_of_range("Index out of range");
	}

	delete vehicles[index];

	for (int i = index; i < size - 1; ++i) {
		vehicles[i] = vehicles[i + 1];
	}

	--size;

	if (size == 0) {
		delete[] vehicles;
		vehicles = nullptr;
	}
}

void Keeper::printall() const {
	for (int i = 0; i < size; ++i) {
		cout << i + 1 << ": ";
		vehicles[i]->print();
	}
}

