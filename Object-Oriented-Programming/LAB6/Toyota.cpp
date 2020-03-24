#include "Toyota.h"
#include "Weather.h"
#include "Extends.h"

Toyota::Toyota()
{
	Name = ContextName(__FILE__);
	SetFuelCapacity(50);
	SetFuelConsuption(9);
	SetAverageSpeed(60, Weather::Rain);
	SetAverageSpeed(170, Weather::Sunny);
	SetAverageSpeed(70, Weather::Snow);
}

/*
 * Sets
 */

void Toyota::SetFuelCapacity(int value)
{
	fuel_capacity = value;
}
void Toyota::SetFuelConsuption(float value)
{
	fuel_consumption = value;
}
void Toyota::SetAverageSpeed(float value, int wh)
{
	average_speed[wh] = value;
}

/*
 * Gets
 */

const char* Toyota::GetName()
{
	return Name;
}
int Toyota::GetFuelCapacity()
{
	return fuel_capacity;
}
float Toyota::GetFuelConsuption()
{
	return fuel_consumption;
}
float Toyota::GetAverageSpeed(int value)
{
	return average_speed[value];
}
