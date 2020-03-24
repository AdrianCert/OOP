#include "ICar.h"

class Mazda : public Car
{
	int fuel_capacity = 30;
	float fuel_consumption = 10;
	float average_speed[Weather::Count];
	char* Name = nullptr;
public:
	Mazda();
	const char* GetName() override;
	int GetFuelCapacity() override;
	float GetFuelConsuption() override;
	float GetAverageSpeed(int) override;
protected:
	void SetFuelCapacity(int) override;
	void SetFuelConsuption(float) override;
	void SetAverageSpeed(float, int) override;
};

