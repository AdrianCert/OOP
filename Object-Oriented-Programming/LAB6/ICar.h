#include "Weather.h"
#include "Extends.h"
#ifndef INTERFACE_CAR_H
#define INTERFACE_CAR_H
class Car
{
protected:
public:
	virtual const char* GetName() = 0;
	virtual int GetFuelCapacity() = 0;
	virtual float GetFuelConsuption() = 0;
	virtual float GetAverageSpeed(int) = 0;
protected:
	virtual void SetFuelCapacity(int) = 0;
	virtual void SetFuelConsuption(float) = 0;
	virtual void SetAverageSpeed(float, int) = 0;
};

#endif // !INTERFACE_CAR_H