#include "VehicleSurrogate.h"

VehicleSurrogate::VehicleSurrogate()
	:vp(nullptr)
{
	
}

VehicleSurrogate::VehicleSurrogate(const Vehicle& v)
	:vp(v.Copy())
{
	
}

VehicleSurrogate::~VehicleSurrogate()
{
	delete vp;
}

VehicleSurrogate::VehicleSurrogate(const VehicleSurrogate& vs)
	:vp(vs.vp ? vs.vp->Copy() : nullptr)
{
	
}

VehicleSurrogate& VehicleSurrogate::operator=(const VehicleSurrogate& vs)
{
	if (this != &vs)
	{
		delete vp;
		vp = (vs.vp ? vs.vp->Copy() : nullptr);
	}
	return *this;
}

double VehicleSurrogate::Weight() const
{
	if (vp == 0)
		throw "Empty VehicleSurrogate.Weight()";
	return vp->Weight();
}

void VehicleSurrogate::Start()
{
	if (vp == 0)
		throw "Empty VehicleSurrogate.Start()";
	return vp->Start();
}