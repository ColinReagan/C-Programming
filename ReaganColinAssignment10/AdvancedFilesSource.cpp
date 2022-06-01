// Colin Reagan
// 3/26/2022
// C++ Programming
// Advanced File Operations (Assignment 10)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>

using namespace std;

const int NAME_SIZE = 40;

struct Product_S
{
	long prodNumber;
	char prodName[NAME_SIZE];
	double prodPrice;
	int prodQuantity;
};

// Prototypes
int showMenu();
void Create_File(fstream& binOut, string binaryFile);
void Display_File(fstream& binIn);
void Display_Record(fstream& binInOut);
void Modify_Record(fstream& binInOut);

int main()
{

	string binaryFile;

	cout << "\nEnter the text file name: ";
	getline(cin, binaryFile);

	// opening binary file in function
	fstream binOut;

	Create_File(binOut, binaryFile);

	fstream binIn(binaryFile, ios::in | ios::binary);

	// Test if file will open
	if (binIn.fail())
	{
		cout << "\nFile not found...program will end";
		system("pause");
		return 0;
	}
	
	// For display record function
	fstream binInOut(binaryFile, ios::in | ios::out | ios::binary);

	// Menu 
	int choice = showMenu();
	while (choice != 4)
	{
		if (choice == 1)
		{
			Display_File(binIn);
		}
		else if (choice == 2)
		{
			Display_Record(binInOut);
		}
		else if (choice == 3)
		{
			Modify_Record(binInOut);
		}
		choice = showMenu();
	}


	cout << endl << endl;
	system("pause");
	return 0;
}

void Modify_Record(fstream &binInOut)
{
	Product_S prod;
	long recNum;

	long number;
	char name[NAME_SIZE];
	double price;
	int quantity;

	cout << "Enter the record number of the product to be modified: ";
	cin >> recNum;
	cout << endl;

	// Clears eof flag
	binInOut.clear();
	// Seeks beginning of the file
	binInOut.seekg(0L, ios::beg);

	// Seek beginning of the record to modify then read
	binInOut.seekg(recNum * sizeof(prod), ios::beg);
	binInOut.read(reinterpret_cast<char*>(&prod), sizeof(prod));

	// Allows user to modify the record they select
	cout << "\nEnter the new information here ";
	cout << "\nEnter the product number: ";
	cin >> number;
	prod.prodNumber = number;

	cout << "\nEnter the product name: ";
	cin.ignore();
	cin.get(name, NAME_SIZE);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	strcpy(prod.prodName, name);

	cout << "\nEnter the product price: ";
	cin >> price;
	prod.prodPrice = price;

	cout << "\nEnter the product quantity: ";
	cin >> quantity;
	prod.prodQuantity = quantity;

	// Moves back to beginning of the record
	binInOut.seekp(recNum * sizeof(prod), ios::beg);
	// Rewrite the record for modification
	binInOut.write(reinterpret_cast<char*>(&prod), sizeof(prod));

	cout << "Record #" << recNum << " has been updated. " << endl;

}

void Display_Record(fstream& binInOut)
{

	long recNum;
	Product_S prodt;

	cout << "\nEnter the product record number you want to display: ";
	cin >> recNum;

	// Clears eof flag
	binInOut.clear();
	// Seeks to the beginning of the file
	binInOut.seekg(0L, ios::beg);
	
	// Seeks to beginning of the record to be read
	binInOut.seekg(recNum * sizeof(prodt), ios::beg);
	binInOut.read(reinterpret_cast<char*> (&prodt), sizeof(prodt));

	cout << "Record #" << recNum << endl;
	cout << "\nProduct number: " << prodt.prodNumber;
	cout << "\nProduct name: " << prodt.prodName;
	cout << "\nProduct price: $" << prodt.prodPrice;
	cout << "\nProduct quantity: " << prodt.prodQuantity;

}

// Displays the file with the information that the user inputted
void Display_File(fstream& binIn)
{
	long number;
	char name[NAME_SIZE];
	double price;
	int quantity;

	Product_S prod;

	cout << setprecision(2) << fixed;
	// Displays the information saved from the structure into the file
	while (binIn.read(reinterpret_cast<char*> (&prod), sizeof(Product_S)))
	{
		cout << "\nProduct number: " << prod.prodNumber;
		cout << "\nProduct name: " << prod.prodName;
		cout << "\nProduct price: " << prod.prodPrice;
		cout << "\nProduct quantity: " << prod.prodQuantity;
	}
	binIn.close();
}

// Creates the file with user inputted information
void Create_File(fstream& binOut, string binaryFile)
{
	binOut.open(binaryFile, ios::out | ios::binary);
	Product_S pro;

	long number;
	char name[NAME_SIZE];
	double price; 
	int quantity;

	bool again = true;
	// Asks the user to input product information via looping
	while (again)
	{

		cout << "\nEnter the product number: ";
		cin >> number;
		pro.prodNumber = number;

		cout << "\nEnter the product name: ";
		cin.ignore();
		cin.get(name, NAME_SIZE);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		strcpy(pro.prodName, name);

		cout << "\nEnter the product price: ";
		cin >> price;
		pro.prodPrice = price;

		cout << "\nEnter the product quantity: ";
		cin >> quantity;
		pro.prodQuantity = quantity;

		binOut.write(reinterpret_cast<char*>(&pro), sizeof(pro));

		cout << "\nEnter 1 for more data else enter 0: ";
		cin >> again;
	}
	binOut.close();
}

int showMenu()
{
	int choice;
	cout << "\n\n1. Display the entire inventory";
	cout << "\n2. Display a particular product";
	cout << "\n3. Modify a product";
	cout << "\n4. Exit the program";
	cout << "\nPlease enter a choice: ";
	cin >> choice;
	cout << endl;
	return choice;
}