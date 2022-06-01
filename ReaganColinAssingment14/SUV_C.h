#ifndef SUV_C_
#define SUV_C_

#include "Car_C.h"

class SUV_C : public Car_C
{
private:
	int gasCap;
public:
	SUV_C();
	SUV_C(int, int, string, int);

	int Get_GasCap() const;
	void Set_GasCap(int);

	void Display_Info();

};
#endif
