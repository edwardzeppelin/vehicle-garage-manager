# Vehicle Garage Manager

A C++ object-oriented console application designed to manage a vehicle database containing cars, motorcycles, and buses.

## Features

* **Polymorphic Architecture:** Uses an abstract base class `Garage` to provide a unified interface for different vehicle types.
* **Dynamic Memory Management:** Utilizes a custom `Keeper` container class to dynamically allocate, reallocate, and delete vehicle objects without memory leaks.
* **Binary Serialization:** Features custom binary file I/O to save (`serialize`) and load (`deserialize`) the entire state of the garage to a `garage.bin` file.
* **Interactive CLI Menu:** Includes a text-based menu for adding, editing, listing, and deleting vehicles with basic input error handling.

## Project Structure

* main.cpp — Manages the console UI menu loop and handles direct input validation.
* garage.h — Defines the abstract interface class with pure virtual functions.
* car.h / car.cpp — Implements the specific properties and serialization for cars.
* moto.h / moto.cpp — Implements the specific properties and serialization for motorcycles.
* bus.h / bus.cpp — Implements the specific properties and serialization for buses.
* keeper.h / keeper.cpp — Manages the array configuration, safe index accessing, and file streams.
