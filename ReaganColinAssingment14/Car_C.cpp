#include "Car_C.h"

Car_C::Car_C() : Vehicle_C()	// Calling default constructor from vehicle class
{
	numDoors = 0;
}

Car_C::Car_C(int numD) : Vehicle_C()
{
	numDoors = numD;
}

Car_C::Car_C(int numD, string man, int yearB) : Vehicle_C(man, yearB)
{
	numDoors = numD;
}

void Car_C::Set_NumDoors(int numD)
{
	numDoors = numD;
}

int Car_C::Get_NumDoors() const
{
	return numDoors;
}

void Car_C::Display_Info()
{
	cout << "\nManufacturer: " << Get_Manufacturer();
	cout << "\nYear Built: " << Get_YearBuilt();
	cout << "\nNumber of Doors: " << Get_NumDoors();
}