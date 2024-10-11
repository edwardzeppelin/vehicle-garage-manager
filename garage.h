#ifndef GARAGE_H
#define GARAGE_H

#include <iostream>
using namespace std;

class Garage
{
public:

	virtual void print() const = 0;
	virtual void setbrand(const string& newbrand) = 0;
	virtual void setmodel(const string& newmodel) = 0;
	virtual void setenginev(const float& newenginev) = 0;
	virtual void setcolour(const string& newcolour) = 0;
	virtual void setgearbox(const string& newgearbox) = 0;
	virtual void sethorsepwr(const int& newhorsepwr) = 0;
	virtual void setterrain(const string& newterrain) = 0;
	virtual void setsitseats(const int& newsitseats) = 0;
	virtual void setallseats(const int& newallseats) = 0;
	virtual void setdestination(const string& newdestination) = 0;
	virtual void getveh() = 0;

	virtual string gettype() const = 0;

	virtual ~Garage() {}

};

#endif