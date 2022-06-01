// Colin Reagan
// CIS 1202
// 02/05/2022
// Programming Assignment #34 (Store, Display, and sort the income for rental properties part 2)

#include<iostream>
#include<iomanip>

using namespace std;

// Prototype Functions
int Get_Menu_Item();
void Enter_Rents(float* rentalIncome, int SIZE, int* numRent);
void Display_Rents(float* rentalIncome, int* numRent);
void Display_Memory_Locations(float* rentalIncome, int* numRent);
float* Sum_Rents(float* rentalIncome, int numRent);
void Selection_Sort(float* rentalIncome, int* numRent);

int main()
{
	// Declare Arrays
	const int SIZE = 7;
	float rentalIncome[SIZE];

	// Declare Variable
	int numRent = 0;
	float* sum_p; // Value

	// Display menu & prompt user for menu choice
	cout << "Selection Menu";
	int choice = Get_Menu_Item();
	while (choice != 6)
	{
		if (choice == 1)
		{
			Enter_Rents(rentalIncome, SIZE, &numRent);
		}
		else if (choice == 2)
		{
			Display_Rents(rentalIncome, &numRent);
		}
		else if (choice == 3)
		{
			Display_Memory_Locations(rentalIncome, &numRent);
		}
		else if (choice == 4)
		{
			sum_p = Sum_Rents(rentalIncome, numRent);
			cout << "Total rents = $" << *sum_p;

			delete[] sum_p;
		}
		else if (choice == 5)
		{
			Selection_Sort(rentalIncome, &numRent);
		}
		else
		{
			cout << "Invalid menu choice. Please try again. " << endl << endl;
		}
		choice = Get_Menu_Item();
	}
	cout << endl << endl;
	system("pause");
	return 0;
}

//Display option menu
int Get_Menu_Item()
{
	int choice;
	cout << "\nOptions:";
	cout << "\n1. Enter rent amounts";
	cout << "\n2. Display rents";
	cout << "\n3. Display Memory Locations";
	cout << "\n4. Display Total Sum";
	cout << "\n5. Sort rent amounts, low to high";
	cout << "\n6. Exit";
	cout << "\n\nEnter menu choice: ";
	cin >> choice;
	cout << endl;
	return choice;
}

// Input Rent Amounts
void Enter_Rents(float* rentalIncome, int SIZE, int* numRent)
{
	bool again = true;

	for (int i = 0; i < SIZE && again; i++)
	{
		cout << "\nEnter rent amount $: " << i + 1 << ": ";
		cin >> *(rentalIncome + i);

		(*numRent)++;

		cout << "\nEnter 1 for another rent else enter 0 to quit: ";
		cin >> again;
	}
}

// Display Rent Amount
void Display_Rents(float* rentalIncome, int* numRent)
{
	for (int i = 0; i < *numRent; i++)
	{
		cout << "\nRental property #" << i + 1 << ": $" << *(rentalIncome + i) << endl;
	}
}

// Display memory locations of rent
void Display_Memory_Locations(float* rentalIncome, int* numRent)
{
	for (int i = 0; i < *numRent; i++)
	{
		cout << "Memory address of cell " << i << " = " << *(rentalIncome + i) << endl;
	}
	cout << endl;
}

// Add up the totals to create a sum using DMA
float* Sum_Rents(float* rentalIncome, int numRent)
{
	float* sum_p = new float;
	*sum_p = 0; // Value
	
	for (int i = 0; i < numRent; i++)
	{
		*sum_p += *(rentalIncome + i);
	}
	return sum_p; // Address
}

// Sort rental income by ascending order
void Selection_Sort(float *rentalIncome, int* numRent)
{
	int i;
	for (int c = 0; c < (*numRent - 1); c++)
	{
		i = c;
		for (int b = c + 1; b < *numRent; b++)
		{
			if (*(rentalIncome + b) < *(rentalIncome + i))
			{
				i = b;
			}
		}
		int x = *(rentalIncome + i);
		*(rentalIncome + i) = *(rentalIncome + c);
		*(rentalIncome + c) = x;
	}
	Display_Rents(rentalIncome, numRent);
}