/*
Colin Reagan
5/6/2022
CIS 1202
Final Project
*/

#include "Employee_C.h"

#include<string>
#include<cmath>
#include<fstream>
#include<iostream>
#include<iomanip>

using namespace std;

const int num = 100;

int showMenu()
{
	int choice;
	cout << "\n1. Display IDs";
	cout << "\n2. Find Employee";
	cout << "\n3. Exit";
	cout << "\nPlease select a menu option: ";
	cin >> choice;
	cout << endl;
	return choice;
}

Employee_C *Fill_Array()
{
	string nm;
	int id;
	float sal;
	char gen;

	Employee_C* employee = new Employee_C[100];

	bool again = true;

	while (again)
	{
		for (int i = 0; i < num && again; i++)
		{
			cout << "\nEnter employee name: ";
			getline(cin, nm);
			employee[i].Set_Name(nm);

			cout << "\nEnter employee id: ";
			cin >> id;
			employee[i].Set_ID(id);

			cout << fixed << setprecision(2);
			cout << "\nEnter employee salary: ";
			cin >> sal;
			employee[i].Set_Salary(sal);

			cout << "\nEnter employee gender: ";
			cin >> gen;
			employee[i].Set_Gender(gen);

			totalSalaries += employee[i].Get_Salary();

			cout << "\nEnter 1 to enter another employee else enter 0: ";
			cin >> again;
			cin.ignore();
		}
		return employee;
	}
}

void Display_ID(Employee_C *arr)
{
		for (int i = 0; i < 5; i++)
		{
			cout << "\nList of Employee IDs you entered: " << arr[i].Get_ID();
		}
}

int Find_Employee(Employee_C* arr)
{

	int searchValue;
	cout << "\nEnter an Employee ID to search: ";
	cin >> searchValue;

	for (int i = 0; i < 5; i++)
	{
		if (searchValue == arr[i].Get_ID())
		{
			cout << "Employee ID " << arr[i].Get_ID() << " found " << endl;
			cout << "Employee Name: " << arr[i].Get_Name() << endl;
			cout << fixed << setprecision(2);
			cout << "Employee Salary: $" << arr[i].Get_Salary() << endl;
			cout << "Employee Gender: " << arr[i].Get_Gender() << endl;
			return i;
		}
		else
		{
			cout << "\nNo matching Employee ID found";
		}
	}
} 

int main()
{
	Employee_C* employee;

	employee = Fill_Array();

	int choice = showMenu();
	while (choice != 3)
	{
		if (choice == 1)
		{
			Display_ID(employee);
		}
		else if (choice == 2)
		{
			Find_Employee(employee);
		}
		choice = showMenu();
	}

	cout << fixed << setprecision(2);
	cout << "\nTotal salary: $" << totalSalaries << endl;

	cout << endl << endl;
	system("pause");
	return 0;
}

