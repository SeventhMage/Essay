#ifndef _VEHICLE_SURROGATE_H_
#define _VEHICLE_SURROGATE_H_

#include "Surrogate.h"
#include "Vehicle.h"

class VehicleSurrogate : public Surrogate
{
public:
	VehicleSurrogate();
	VehicleSurrogate(const Vehicle&);
	~VehicleSurrogate();
	VehicleSurrogate(const VehicleSurrogate&);
	VehicleSurrogate& operator=(const VehicleSurrogate&);
	
	//from Vehicle
	double Weight() const;
	void Start();
private:
	Vehicle *vp;
};

#endif