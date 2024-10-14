#include "car.h"

void Car::print() const {
	cout << "Car: " << brand << " " << model << " " << colour << " " << enginev << " " << gearbox << endl;
}

void Car::getveh() {
	cout << brand << " " << model << " " << enginev << " " << colour << " " << gearbox << endl;
}

Car::Car(const Car& other) {
	brand = other.brand;
	model = other.model;
	enginev = other.enginev;
	colour = other.colour;
	gearbox = other.gearbox;
	cout << "Car copy constructor called" << endl;
}

void Car::serialize(ofstream& out) const {
	size_t len;

	len = brand.size();
	out.write(reinterpret_cast<const char*>(&len), sizeof(len));
	out.write(brand.c_str(), len);

	len = model.size();
	out.write(reinterpret_cast<const char*>(&len), sizeof(len));
	out.write(model.c_str(), len);

	out.write(reinterpret_cast<const char*>(&enginev), sizeof(enginev));

	len = colour.size();
	out.write(reinterpret_cast<const char*>(&len), sizeof(len));
	out.write(colour.c_str(), len);

	len = gearbox.size();
	out.write(reinterpret_cast<const char*>(&len), sizeof(len));
	out.write(gearbox.c_str(), len);
}

void Car::deserialize(ifstream& in) {
	size_t len;
	char* buffer;

	in.read(reinterpret_cast<char*>(&len), sizeof(len));
	buffer = new char[len + 1];
	in.read(buffer, len);
	buffer[len] = '\0';
	brand = buffer;
	delete[] buffer;

	in.read(reinterpret_cast<char*>(&len), sizeof(len));
	buffer = new char[len + 1];
	in.read(buffer, len);
	buffer[len] = '\0';
	model = buffer;
	delete[] buffer;

	in.read(reinterpret_cast<char*>(&enginev), sizeof(enginev));

	in.read(reinterpret_cast<char*>(&len), sizeof(len));
	buffer = new char[len + 1];
	in.read(buffer, len);
	buffer[len] = '\0';
	colour = buffer;
	delete[] buffer;

	in.read(reinterpret_cast<char*>(&len), sizeof(len));
	buffer = new char[len + 1];
	in.read(buffer, len);
	buffer[len] = '\0';
	gearbox = buffer;
	delete[] buffer;
}

