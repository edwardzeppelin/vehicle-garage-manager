#include "moto.h"

void Motorcycle::print() const {
	cout << "Motorcycle: " << brand << " " << model << " " << enginev << " " << horsepwr << " " << terrain << endl;
}

Motorcycle::Motorcycle(const Motorcycle& other) {
	brand = other.brand;
	model = other.model;
	enginev = other.enginev;
	horsepwr = other.horsepwr;
	terrain = other.terrain;
	cout << "Motorcycle copy constructor called" << endl;
}

void Motorcycle::getveh() {
	cout << brand << " " << model << " " << enginev << " " << horsepwr << " " << terrain << endl;
}

void Motorcycle::serialize(ofstream& out) const {
	size_t len;

	len = brand.size();
	out.write(reinterpret_cast<const char*>(&len), sizeof(len));
	out.write(brand.c_str(), len);

	len = model.size();
	out.write(reinterpret_cast<const char*>(&len), sizeof(len));
	out.write(model.c_str(), len);

	out.write(reinterpret_cast<const char*>(&enginev), sizeof(enginev));

	out.write(reinterpret_cast<const char*>(&horsepwr), sizeof(horsepwr));

	len = terrain.size();
	out.write(reinterpret_cast<const char*>(&len), sizeof(len));
	out.write(terrain.c_str(), len);
}

void Motorcycle::deserialize(ifstream& in) {
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

	in.read(reinterpret_cast<char*>(&horsepwr), sizeof(horsepwr));

	in.read(reinterpret_cast<char*>(&len), sizeof(len));
	buffer = new char[len + 1];
	in.read(buffer, len);
	buffer[len] = '\0';
	terrain = buffer;
	delete[] buffer;
}

