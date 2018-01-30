#ifndef _AUTOMOBILE_H_
#define _AUTOMOBILE_H_

#include "Vehicle.h"

class Automobile : public Vehicle
{
public:
	virtual Vehicle* Copy() const;
	virtual double Weight() const;
	virtual void Start();
};

#endif