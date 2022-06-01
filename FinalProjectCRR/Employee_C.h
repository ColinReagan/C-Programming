#ifndef Employee_C_
#define Employee_C_

#include <string>
#include <iostream>

using namespace std;
static int totalSalaries = 0;

class Employee_C
{
private:
	string name;
	int idNum;
	float salary;
	char gender;
public:
	Employee_C();	// Default Constructor
	Employee_C(string, int, float, char);

	void Set_Name(string);
	void Set_ID(int);
	void Set_Salary(float);
	void Set_Gender(char);
	void Set_TotalSalaries();

	string Get_Name() const;
	int Get_ID() const;
	float Get_Salary() const;
	char Get_Gender() const;
	int Get_TotalSalaries();

	void display();
};
#endif
