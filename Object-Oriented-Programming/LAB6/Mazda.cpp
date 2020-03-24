#include "Mazda.h"
#include "Weather.h"
#include "Extends.h"

Mazda::Mazda()
{
	Name = ContextName(__FILE__);
	SetFuelCapacity(70);
	SetFuelConsuption(11);
	SetAverageSpeed(70, Weather::Rain);
	SetAverageSpeed(80, Weather::Sunny);
	SetAverageSpeed(50, Weather::Snow);
}

/*
 * Sets
 */

void Mazda::SetFuelCapacity(int value)
{
	fuel_capacity = value;
}
void Mazda::SetFuelConsuption(float value)
{
	fuel_consumption = value;
}
void Mazda::SetAverageSpeed(float value, int wh)
{
	average_speed[wh] = value;
}

/*
 * Gets
 */

const char* Mazda::GetName()
{
	return Name;
}
int Mazda::GetFuelCapacity()
{
	return fuel_capacity;
}
float Mazda::GetFuelConsuption()
{
	return fuel_consumption;
}
float Mazda::GetAverageSpeed(int value)
{
	return average_speed[value];
}
