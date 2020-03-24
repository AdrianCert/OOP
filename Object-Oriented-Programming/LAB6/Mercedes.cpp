#include "Mercedes.h"
#include "Weather.h"
#include "Extends.h"

Mercedes::Mercedes()
{
	Name = ContextName(__FILE__);
	SetFuelCapacity(120);
	SetFuelConsuption(20);
	SetAverageSpeed(40, Weather::Rain);
	SetAverageSpeed(170, Weather::Sunny);
	SetAverageSpeed(20, Weather::Snow);
}

/*
 * Sets
 */

void Mercedes::SetFuelCapacity(int value)
{
	fuel_capacity = value;
}
void Mercedes::SetFuelConsuption(float value)
{
	fuel_consumption = value;
}
void Mercedes::SetAverageSpeed(float value, int wh)
{
	average_speed[wh] = value;
}

/*
 * Gets
 */

const char* Mercedes::GetName()
{
	return Name;
}
int Mercedes::GetFuelCapacity()
{
	return fuel_capacity;
}
float Mercedes::GetFuelConsuption()
{
	return fuel_consumption;
}
float Mercedes::GetAverageSpeed(int value)
{
	return average_speed[value];
}
