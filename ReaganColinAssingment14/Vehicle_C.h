#ifndef Vehicle_C_
#define Vehicle_C_

#include <string>
#include <iostream>

using namespace std;

class Vehicle_C
{
private:
	string manufacturer;
	int yearBuilt;
public:
	Vehicle_C(); // Default Constructor
	Vehicle_C(string, int); // Accepts name and year built

	void Set_Manufacturer(string);
	void Set_YearBuilt(int);

	string Get_Manufacturer() const;
	int Get_YearBuilt() const;

	void Display_Info();  // Redefined function

};
#endif