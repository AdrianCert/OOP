#include "ICar.h"
#ifndef CIRCUIT_H
#define CIRCUIT_H

struct CarRezult
{
	char* name = nullptr;
	bool finRace = false;
	float finTime = -1;
	void Write(const char * name, bool finRace, float fintime);
};

class Circuit
{
	int Length = 1;
	int Weather = 0;
	Car** Cars = nullptr;
	int count_car = 0;
	CarRezult* car_race = nullptr;
public:
	Circuit();
	void SetLength(int);
	void SetWeather(int);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks(); // it will print the time each car needed to finish the circuit
	void ShowWhoDidNotFinis(); // it is possible that some cars don't have enough fuel to finish the circuit
};

#endif // !CIRCUIT_H