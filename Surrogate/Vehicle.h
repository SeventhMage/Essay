#ifndef _VEHICLE_H_
#define _VEHICLE_H_

class Vehicle
{
public:
	virtual ~Vehicle(){}
	
	virtual Vehicle *Copy() const = 0;
	virtual double Weight() const = 0;
	virtual void Start() = 0;
};

#endif