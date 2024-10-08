#ifndef KEEPER_H
#define KEEPER_H

#include "garage.h"
#include "car.h"
#include "moto.h"
#include "bus.h"
#include <iostream>
using namespace std;

class Keeper
{
private:
	int size;
	int cpct;
	Garage** vehicles;

	void resize();

public:
	Keeper() : vehicles(nullptr), size(0), cpct(0) {}

	~Keeper();

	void add(Garage* vehicle);

	void printall() const;

	Garage* operator[](int index) const {
		if (index >= size)
			throw out_of_range("Index out of range");
		return vehicles[index];
	}


};

#endif KEEPER_H