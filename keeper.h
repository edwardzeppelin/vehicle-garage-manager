#ifndef KEEPER_H
#define KEEPER_H

#include "garage.h"
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
	Keeper() : vehicles(nullptr), size(0), cpct(0) {}

	~Keeper();

	void add(Garage* vehicle);

	void deletevehicle(int index);

	void printall() const;

	Garage* operator[](int index) const {
		if (index >= size)
			throw out_of_range("Index out of range");
		return vehicles[index];
	}


	void saveToFile(const std::string& filename) const {
		std::ofstream out(filename);
		if (out.is_open()) {
			for (int i = 0; i < size; ++i) {
				vehicles[i]->serialize(out);
			}
			out.close();
		}
		else {
			std::cerr << "Unable to open file: " << filename << std::endl;
		}
	}

	void loadFromFile(const std::string& filename) {
		std::ifstream in(filename);
		if (in.is_open()) {
			std::string type;
			while (in >> type) {
				if (type == "Car:") {
					Car* car = new Car();
					car->deserialize(in);
					add(car);
				}
				else if (type == "Moto:") {
					Motorcycle* moto = new Motorcycle();
					moto->deserialize(in);
					add(moto);
				}
				else if (type == "Bus:") {
					Bus* bus = new Bus();
					bus->deserialize(in);
					add(bus);
				}
			}
			in.close();
		}
		else {
			std::cerr << "Unable to open file: " << filename << std::endl;
		}
	}


};

#endif KEEPER_H