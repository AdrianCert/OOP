#include "Extends.h"
#include "Ford.h"
#include "Weather.h"

Ford::Ford()
{
	Name = ContextName(__FILE__);
	SetFuelCapacity(60);
	SetFuelConsuption(9);
	SetAverageSpeed(50, Weather::Rain);
	SetAverageSpeed(100, Weather::Sunny);
	SetAverageSpeed(40, Weather::Snow);
}

/*
 * Sets
 */

void Ford::SetFuelCapacity(int value)
{
	fuel_capacity = value;
}
void Ford::SetFuelConsuption(float value)
{
	fuel_consumption = value;
}
void Ford::SetAverageSpeed(float value, int wh)
{
	average_speed[wh] = value;
}

/*
 * Gets
 */
const char* Ford::GetName()
{
	return Name;
}
int Ford::GetFuelCapacity()
{
	return fuel_capacity;
}
float Ford::GetFuelConsuption()
{
	return fuel_consumption;
}
float Ford::GetAverageSpeed(int value)
{
	return average_speed[value];
}
