#ifndef GARAGE_H
#define GARAGE_H

#include <iostream>
using namespace std;

class Garage
{
public:

	virtual void print() const = 0;
	virtual ~Garage() {}

};

#endif