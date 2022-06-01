#include "SUV_C.h"

SUV_C::SUV_C() : Car_C()
{
	gasCap = 0;
}

SUV_C::SUV_C(int gasC, int numD, string man, int yearB) : Car_C(numD, man, yearB)
{
	gasCap = gasC;
}

void SUV_C::Set_GasCap(int gasC)
{
	gasCap = gasC;
}

int SUV_C::Get_GasCap() const
{
	return gasCap;
}

void SUV_C::Display_Info()
{
	cout << "\nManufacturer Name: " << Get_Manufacturer();
	cout << "\nYear Built: " << Get_YearBuilt();
	cout << "\nNumber of Doors: " << Get_NumDoors();
	cout << "\nGas Tank Capacity: " << Get_GasCap();
}