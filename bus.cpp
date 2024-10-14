#include "bus.h"

void Bus::print() const {
	cout << "Bus: " << brand << " " << model << " " << sitseats << " " << allseats << " " << destination << endl;
}

Bus::Bus(const Bus& other) {
	brand = other.brand;
	model = other.model;
	sitseats = other.sitseats;
	allseats = other.allseats;
	destination = other.destination;
	cout << "Bus copy constructor called" << endl;
}

void Bus::getveh() {
	cout << brand << " " << model << " " << sitseats << " " << allseats << " " << destination << endl;
}

void Bus::serialize(ofstream& out) const {
	size_t len;

	len = brand.size();
	out.write(reinterpret_cast<const char*>(&len), sizeof(len));
	out.write(brand.c_str(), len);

	len = model.size();
	out.write(reinterpret_cast<const char*>(&len), sizeof(len));
	out.write(model.c_str(), len);

	out.write(reinterpret_cast<const char*>(&sitseats), sizeof(sitseats));

	out.write(reinterpret_cast<const char*>(&allseats), sizeof(allseats));

	len = destination.size();
	out.write(reinterpret_cast<const char*>(&len), sizeof(len));
	out.write(destination.c_str(), len);
}

void Bus::deserialize(ifstream& in) {
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

	in.read(reinterpret_cast<char*>(&sitseats), sizeof(sitseats));

	in.read(reinterpret_cast<char*>(&allseats), sizeof(allseats));

	in.read(reinterpret_cast<char*>(&len), sizeof(len));
	buffer = new char[len + 1];
	in.read(buffer, len);
	buffer[len] = '\0';
	destination = buffer;
	delete[] buffer;
}

