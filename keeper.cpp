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

Keeper::Keeper(const Keeper& other) : size(other.size), cpct(other.cpct) {
	if (size > 0) {
		vehicles = new Garage * [cpct];

		for (int i = 0; i < size; ++i) {

			if (Car* car = dynamic_cast<Car*>(other.vehicles[i])) {
				vehicles[i] = new Car(*car); 
			}
			else if (Motorcycle* moto = dynamic_cast<Motorcycle*>(other.vehicles[i])) {
				vehicles[i] = new Motorcycle(*moto);
			}
			else if (Bus* bus = dynamic_cast<Bus*>(other.vehicles[i])) {
				vehicles[i] = new Bus(*bus);
			}
			else {
				vehicles[i] = nullptr; 
			}
		}
	}
	else {
		vehicles = nullptr; 
	}

	cout << "Keeper copy constructor called" << endl;

}

Keeper::~Keeper() {
	for (int i = 0; i < size; ++i)
		delete vehicles[i];
	delete[] vehicles;
	cout << "Keeper deconstructor called" << endl;
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

Garage* Keeper::operator[](int index) const {
	if (index >= size)
		throw out_of_range("Index out of range");
	return vehicles[index];
}

void Keeper::serialize(const string& filename) const {
	ofstream out(filename, ios::binary);
	if (!out) {
		cerr << "Error opening file for writing\n";
		return;
	}

	out.write(reinterpret_cast<const char*>(&size), sizeof(size));
	for (int i = 0; i < size; ++i) {
		if (dynamic_cast<Car*>(vehicles[i])) {
			char type = 'C'; // Car
			out.write(&type, sizeof(type));
		}
		else if (dynamic_cast<Motorcycle*>(vehicles[i])) {
			char type = 'M'; // Motorcycle
			out.write(&type, sizeof(type));
		}
		else if (dynamic_cast<Bus*>(vehicles[i])) {
			char type = 'B'; // Bus
			out.write(&type, sizeof(type));
		}
		vehicles[i]->serialize(out);
	}
	out.close();

	cout << "Saved" << endl;

}

void Keeper::deserialize(const string& filename) {
	ifstream in(filename, ios::binary);
	if (!in) {
		cerr << "Error opening file for reading\n";
		return;
	}

	int newSize;
	in.read(reinterpret_cast<char*>(&newSize), sizeof(newSize));

	for (int i = 0; i < newSize; ++i) {
		char type;
		in.read(&type, sizeof(type));

		Garage* vehicle = nullptr;
		if (type == 'C') {
			vehicle = new Car();
		}
		else if (type == 'M') {
			vehicle = new Motorcycle();
		}
		else if (type == 'B') {
			vehicle = new Bus();
		}

		if (vehicle) {
			vehicle->deserialize(in);
			add(vehicle);
		}
	}
	in.close();

	cout << "Loaded" << endl;

}

