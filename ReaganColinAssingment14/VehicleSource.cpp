/*
Colin Reagan
4/25/2022
CIS 1202 101
Assignment 14 - Vehicle Inheritance
*/

#include "SUV_C.h"

void Display_Info(Vehicle_C& obj);
void Display_Info(Car_C& obj);
void Display_Info(SUV_C& obj);

int main()
{
	string man;
	int yearB;

	Vehicle_C vehicle;
	cout << "\nEnter manufacturer name: ";
	getline(cin, man);
	cout << "\nEnter the year built: ";
	cin >> yearB;
	cin.ignore();
	vehicle.Set_Manufacturer(man);
	vehicle.Set_YearBuilt(yearB);

	Display_Info(vehicle);

	int numD;

	Car_C car;
	cout << "\nEnter manufacturer name: ";
	getline(cin, man);
	cout << "\nEnter the year built: ";
	cin >> yearB;
	cout << "\nEnter the number of doors: ";
	cin >> numD;
	cin.ignore();
	car.Set_Manufacturer(man);
	car.Set_YearBuilt(yearB);
	car.Set_NumDoors(numD);

	Display_Info(car);

	int gasC;

	SUV_C suv;
	cout << "\nEnter manufacturer name: ";
	getline(cin, man);
	cout << "\nEnter the year built: ";
	cin >> yearB;
	cout << "\nEnter the number of doors: ";
	cin >> numD;
	cout << "\nEnter the gas capacity: ";
	cin >> gasC;
	cin.ignore();
	suv.Set_Manufacturer(man);
	suv.Set_YearBuilt(yearB);
	suv.Set_NumDoors(numD);
	suv.Set_GasCap(gasC);

	Display_Info(suv);

	cout << endl << endl;
	system("pause");
	return 0;
}

void Display_Info(Vehicle_C& obj)
{
	obj.Display_Info();
}

void Display_Info(Car_C& obj)
{
	obj.Display_Info();
}

void Display_Info(SUV_C& obj)
{
	obj.Display_Info();
}