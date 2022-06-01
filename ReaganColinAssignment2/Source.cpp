// Colin Reagan
// CIS 1202
// January 22, 2022
// Programming Assignment #2

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Declare function protoypes
int showMenu();
void Load_Arrays(int& numConsoles, string consoleName[], float consoleCost[], int SZ);
void Show_Consoles(string consoleName[], float consoleCost[], int numConsoles);
void Look_Up_Price(string consoleName[], float consoleCost[], int numConsoles);
void Sort_Prices(string consoleName[], float consoleCost[], int numConsoles);
void Highest_Price(string consoleName[], float consoleCost[], int numConsoles);

int main()
{
	// Declare Arrays
	const int SIZE = 15;
	string consoleName[SIZE];
	float consoleCost[SIZE];

	// Declare Variables
	int numConsoles;

	// Call Functions
	Load_Arrays(numConsoles, consoleName, consoleCost, SIZE);

	// Display Menu & Prompt user for menu choice
	cout << "Console Pricing Main Menu" << endl << endl;
	int choice = showMenu();
	while (choice)
	{
		switch (choice)
		{
		case 1:
			Show_Consoles(consoleName, consoleCost, numConsoles);
			break;
		case 2:
			Look_Up_Price(consoleName, consoleCost, numConsoles);
			break;
		case 3:
			Sort_Prices(consoleName, consoleCost, numConsoles);
			break;
		case 4:
			Highest_Price(consoleName, consoleCost, numConsoles);
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "Error: Invalid Input. Please Try Again: ";
		}
		choice = showMenu();
	}

	cout << endl << endl;
	system("pause");
	return 0;
}

// Display option menu
int showMenu()
{
		int choice;
		cout << "\n\nOptions:";
		cout << "\n1. Display all console prices";
		cout << "\n2. Look up the price of a particular console";
		cout << "\n3. Sort prices in descending order";
		cout << "\n4. Display the console with the highest price";
		cout << "\n5. Exit the program";
		cout << "\n\nPlease enter your menu option selection: ";
		cin >> choice;
		cout << endl;
		return choice;
}


void Load_Arrays(int& numConsoles, string consoleName[], float consoleCost[], int SZ)
{
	// Declare input file stream object
	ifstream inFile;

	// Open input file stream
	inFile.open("console.txt");

	// Load data from each line into arrays
	numConsoles = 0;
	while (getline(inFile, consoleName[numConsoles]))
	{
		string temp;
		getline(inFile, temp);
		consoleCost[numConsoles] = stof(temp);
		numConsoles++;
	}
	// Close input file stream
	inFile.close();
}

// Finds the console with the highest price
void Highest_Price(string consoleName[], float consoleCost[], int numConsoles)
{
	string high;
	int highest = 0;
	for (int i = 0; i < numConsoles; i++)
	{
		if (consoleCost[i] > highest)
		{
			high = consoleName[i];
			highest = consoleCost[i];
		}
	}
	cout << "The highest price is $" << highest << " for the console: " << high << endl << endl;
}

// Sorts prices of consoles in descending order for the user
void Sort_Prices(string consoleName[], float consoleCost[], int numConsoles)
{
	// Holding Variables for sorting
	string tempName;
	float tempCost;

	// Selection Sort Method (Descending)
	for (int b = 0; b < numConsoles - 1; b++)
	{
		for (int d = b + 1; d < numConsoles; d++)
		{
			if (consoleCost[d] > consoleCost[b])
			{
				// Moving Elements out of the bracket
				tempName = consoleName[d];
				tempCost = consoleCost[d];
				// Swapping Elements
				consoleName[d] = consoleName[b];
				consoleCost[d] = consoleCost[b];
				// Moving holding elements back into bracket
				consoleName[b] = tempName;
				consoleCost[b] = tempCost;
			}
		}
	}

	Show_Consoles(consoleName, consoleCost, numConsoles);

}

// Allows user to look up a console name to find the price
void Look_Up_Price(string consoleName[], float consoleCost[], int numConsoles)
{
	string search;
	int amount = 0;
	cout << "Enter Console to look up: ";
	cin.ignore();
	getline(cin, search);

	// Linear Search Method
	for (int i = 0; i < numConsoles; i++)
	{
		if (consoleName[i] == search)
		{
			amount = consoleCost[i];
		}
	}
	cout << "The Console Price for " << search << " = $" << amount << endl << endl;
}

// Gives user list of all the consoles
void Show_Consoles(string consoleName[], float consoleCost[], int numConsoles)
{
	cout << setprecision(2) << fixed;

	cout << "\n\nComplete List of Consoles: ";
	for (int c = 0; c < numConsoles; c++)
	{
		cout << "\n\nConsole Name " << consoleName[c];
		cout << "\nConsole Price $" << consoleCost[c];
	}
}

