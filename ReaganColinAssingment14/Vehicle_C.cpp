#include "Vehicle_C.h"

Vehicle_C::Vehicle_C()
{
	manufacturer = "";
	yearBuilt = 0;
}

Vehicle_C::Vehicle_C(string man, int yearB)
{
	manufacturer = man;
	yearBuilt = yearB;
}

void Vehicle_C::Set_Manufacturer(string man)
{
	manufacturer = man;
}

void Vehicle_C::Set_YearBuilt(int yearB)
{
	yearBuilt = yearB;
}

string Vehicle_C::Get_Manufacturer() const
{
	return manufacturer;
}

int Vehicle_C::Get_YearBuilt() const
{
	return yearBuilt;
}

void Vehicle_C::Display_Info()
{
	cout << "\nManufacturer name: " << manufacturer;
	cout << "\nYear built: " << yearBuilt;
}