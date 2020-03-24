#include "Circuit.h"
#include <iostream>
#include <iomanip>

void CarRezult::Write(const char* _name, bool _finRace, float _fintime)
{
	int count = 0;
	for (int i = 0; _name[i] != '\n'; i++) count++;
	name = new char[count + 1];
	for (int i = 0; i <= count; i++) name[i] = _name[i];
	finRace = _finRace;
	finTime = _fintime;
}

Circuit::Circuit()
{
	Cars = new Car*[100];
}

void Circuit::SetLength(int value)
{
	Length = value;
}
void Circuit::SetWeather(int value)
{
	Weather = value;
}
void Circuit::AddCar(Car* value)
{
	Cars[count_car++] = value;
}
void Circuit::Race()
{
	car_race = new CarRezult[count_car];
	for (int i = 0; i < count_car; i++)
	{
		car_race[i].Write(Cars[i]->GetName(), Cars[i]->GetFuelCapacity() / Cars[i]->GetFuelConsuption() * 100 > Length, Length / Cars[i]->GetAverageSpeed(Weather));
	}
}
void Circuit::ShowFinalRanks()
{
	if (car_race != nullptr)
	{
		// sort by intert sort
		if (true)
		{
			int i, key, j;
			CarRezult tmp;
			bool ok = true;
			while (ok)
			{
				ok = false;
				for (i = 1; i < count_car; i++)
				{
					key = i;
					tmp = car_race[key];
					j = i - 1;

					while (j >= 0 && car_race[key].finTime < car_race[j].finTime)
					{
						ok = true;
						car_race[j + 1] = car_race[j];
						j = j - 1;
					}
					car_race[j + 1] = tmp;
				}
			}
		}
		bool have_un_fin = false;
		std::cout << "Race Rezult: " <<std::endl;
		std::cout << '\t' << "Rank" << "\t|" << std::setw(20) << "Car Name" << "\t\t|\t" << "Finish Time" << std::endl;
		int rank = 1;
		for (int i = 0; i < count_car; i++) {
			if ((car_race + i)->finRace)
			{
				std::cout << '\t' << rank++ << "\t|" << std::setw(20) << (car_race + i)->name << "\t\t|\t" << (car_race + i)->finTime << std::endl;
			}
		}
		if (have_un_fin)
		{
			std::cout << "That did not finish:" <<std::endl;
			for (int i = 0; i < count_car; i++)
			{
				if (!(car_race + i)->finRace)
				{
					std::cout << '\t' << "NaN" << "\t|\t" << (car_race + i)->name << "\t|\t" << std::endl;
				}
			}
		}
	}
	else {
		std::cout << "There have been no races on this circuit yet" <<std::endl;
	}
}
void Circuit::ShowWhoDidNotFinis()
{
	if (car_race != nullptr)
	{
		bool wasDispay = false;
		for (int i = 0; i < count_car; i++)
		{
			if (!(car_race + i)->finRace)
			{
				if (!wasDispay) { std::cout << "That did not finish:" << std::endl; wasDispay = true; }
				std::cout << '\t' << "NaN" << "\t|\t" << (car_race + i)->name << "\t|\t" << std::endl;
			}
		}
	}
}