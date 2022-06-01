#ifndef Car_C_
#define Car_C_

#include "Vehicle_C.h"

class Car_C : public Vehicle_C
{
private:
	int numDoors;
public:
	Car_C();	// Default constructor
	Car_C(int);	// Accepts int
	Car_C(int, string, int);

	void Set_NumDoors(int);

	int Get_NumDoors() const;

	void Display_Info();

};
#endif
