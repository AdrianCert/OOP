#include "Extends.h"
#include "Dacia.h"
#include "Weather.h"

Dacia::Dacia()
{
	Name = ContextName(__FILE__);
	SetFuelCapacity(50);
	SetFuelConsuption(9);
	SetAverageSpeed(50, Weather::Rain);
	SetAverageSpeed(100, Weather::Sunny);
	SetAverageSpeed(40, Weather::Snow);
}

/*
 * Sets
 */

void Dacia::SetFuelCapacity(int value)
{
	fuel_capacity = value;
}
void Dacia::SetFuelConsuption(float value)
{
	fuel_consumption = value;
}
void Dacia::SetAverageSpeed(float value, int wh)
{
	average_speed[wh] = value;
}

/*
 * Gets
 */

const char* Dacia::GetName()
{
	return Name;
}

int Dacia::GetFuelCapacity()
{
	return fuel_capacity;
}
float Dacia::GetFuelConsuption()
{
	return fuel_consumption;
}
float Dacia::GetAverageSpeed(int value)
{
	return average_speed[value];
}
