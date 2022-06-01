// Colin Reagan
// CIS 1202 101
// January 16, 2022
// Programming Assignment #1

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Declare Function Prototypes

void loadArrays(string product[], int quantity[], float cost[], int &count);
void calculateValues(int quantity[], float cost[], float value[], int count);
void displayTable(string product[], int quantity[], float cost[], float value[], int count);
int highestValue(float value[], int count);

int main() {

	// Declare Arrays

	const int SIZE = 20;
	string product[SIZE];	// For storing the product names
	int quantity[SIZE];		// For storing the product quantity
	float cost[SIZE];		// For storing the product cost
	float value[SIZE];		// For storing the total value

	// Declare Variables
	int count = -1;
	int highest;
	int total = 0;

	// Call functions
	loadArrays(product, quantity, cost, count);
	calculateValues(quantity, cost, value, count);
	displayTable(product, quantity, cost, value, count);

	// Calculations
	highest = highestValue(value, count);
	cout << "The highest total value is " << value[highest] << " in product 998-W. " << endl;

	system("pause");
	return 0;
}

void loadArrays(string product[], int quantity[], float cost[], int &count) {

	// Declare input file stream object
	ifstream inFile;

	// Open input file stream
	inFile.open("Inventory.txt");

	// Load data from each line into arrays
	while (!inFile.eof()) {
		
		count++;
		inFile >> product[count] >> quantity[count] >> cost[count];
	}

	// Close input file stream
	inFile.close();
}

// Calculates Total Value Section
void calculateValues(int quantity[], float cost[], float value[], int count) {

	for (int i = 0; i < count; i++) {
		value[i] = quantity[i] * cost[i];
	}
}

// Outputs the Data in the Command Console
void displayTable(string product[], int quantity[], float cost[], float value[], int count) {

	float average = 0;

	cout << setw(15) << "Product Code" << setw(15) << "Qty on Hand" << setw(15) << "Cost Each" << setw(15) << "Total Value" << "   " << endl;;
	for (int i = 0; i < count; i++) {

		cout << fixed << setprecision(2) << setw(8) << product[i] << setw(22) << quantity[i] << setw(15) << cost[i] << setw(15);
		average = average + cost[i];

			// Display !!! Warning Indicators
			if (value[i] >= 9000) {
				cout << value[i] << " !!!" << endl;
			}
			else {
				cout << value[i] << "    " << endl;
			}
	}

	average = average / count;

	cout << "\nThe average cost of an inventory item is $" << average << endl;

}

// Determine Highest Total Value
int highestValue(float value[], int count) {
	
	int highest = 0;
	for (int i = 0; i < count; i++) {

		if (value[i] > value[highest])
			highest = i;
	}
	return highest;
}


