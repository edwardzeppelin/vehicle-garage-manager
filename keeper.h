#ifndef KEEPER_H
#define KEEPER_H

#include "car.h"
#include "moto.h"
#include "bus.h"
#include <iostream>
#include <fstream>
using namespace std;

class Keeper
{
private:
	int size;
	int cpct;
	Garage** vehicles;

	void resize();

public:
	Keeper() : vehicles(nullptr), size(0), cpct(0) { cout << "Keeper parametrized constructor called" << endl; }

	Keeper(const Keeper& other);

	~Keeper();

	void add(Garage* vehicle);

	void deletevehicle(int index);

	void printall() const;

	Garage* operator[](int index) const;

	void serialize(const string& filename) const;
	void deserialize(const string& filename);

};

#endif KEEPER_H