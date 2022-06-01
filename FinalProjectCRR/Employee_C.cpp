#include "Employee_C.h"

Employee_C::Employee_C()
{
	name = "";
	idNum = 0;
	salary = 0;
	gender = 'c';
	totalSalaries = -1;
}

Employee_C::Employee_C(string nm, int id, float sal, char gen)
{
	name = nm;
	idNum = id;
	salary = sal;
	gender = gen;
}

void Employee_C::Set_Name(string nm)
{
	name = nm;
}

void Employee_C::Set_ID(int id)
{
	idNum = id;
}

void Employee_C::Set_Salary(float sal)
{
	salary = sal;
}

void Employee_C::Set_Gender(char gen)
{
	gender = gen;
}


string Employee_C::Get_Name() const
{
	return name;
}

int Employee_C::Get_ID() const
{
	return idNum;
}

float Employee_C::Get_Salary() const
{
	return salary;
}

char Employee_C::Get_Gender() const
{
	return gender;
}

void Employee_C::Set_TotalSalaries()
{
	totalSalaries += salary;
}

int Employee_C::Get_TotalSalaries()
{
	return totalSalaries;
}