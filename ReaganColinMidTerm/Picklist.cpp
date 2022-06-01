// Colin Reagan
// 3/5/2022
// C++ Programming
// Mid Term Project

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

struct Product_S
{
	int productID;
	string name;
	char description[50];
	double retailPrice;
};

Product_S Enter_Product(Product_S inventory[], int SIZE, int* numProduct);
void Display_Product(Product_S* inventory, int* numProduct);
void Product_IDs(vector <int>& productID);
void Display_IDs(vector <int>& productID);
void Pick_List(vector <int>& productID, Product_S inventory[], int SIZE, int &numProduct);
int menu();

int main()
{
	vector<int> productID;

	const int SIZE = 100;
	Product_S inventory[SIZE];

	int numProduct = 0;

	int choice = menu();

	while (choice != 6)
	{
		if (choice == 1)
		{
			Enter_Product(inventory, SIZE, &numProduct);
		}
		else if (choice == 2)
		{
			Display_Product(inventory, &numProduct);
		}
		else if (choice == 3)
		{
			Product_IDs(productID);
		}
		else if (choice == 4)
		{
			Display_IDs(productID);
		}
		else if (choice == 5)
		{
			Pick_List(productID, inventory, SIZE, numProduct);
		}
		choice = menu();
	}


	cout << endl << endl;
	system("pause");
	return 0;
}

// Display menu
int menu()
{
	int choice;
	cout << "\n\nPlease select a option";
	cout << "\n1. Enter Product Information";
	cout << "\n2. Display Product";
	cout << "\n3. Enter Product ID's ordered by Customers";
	cout << "\n4. Display Product ID's";
	cout << "\n5. Pick List Test";
	cout << "\n6. Exit";
	cout << "\n\nEnter menu choice: ";
	cin >> choice;
	cout << endl;
	return choice;
}


Product_S Enter_Product(Product_S inventory[], int SIZE, int *numProduct)
{
	Product_S product;

	bool again = true;

		for (int i = 0; i < SIZE && again; i++)
		{
			cout << "\nPlease enter the product name: ";
			cin >> inventory[i].name;

			cout << "\nPlease enter the product id: ";
			cin >> inventory[i].productID;

			cout << "\nPlease enter the product description up to 50 characters: ";
			cin.ignore();
			cin.get(inventory[i].description, 50);

			cout << "\nPlease enter the product retail price: ";
			cin >> inventory[i].retailPrice;

			(*numProduct)++;

			cout << "\nEnter 1 for another product else enter 0: ";
			cin >> again;
		}

	return product;
}

void Pick_List(vector <int> &productID, Product_S inventory[], int SIZE, int &numProduct)
{
		for (int i = 0; i < productID.size(); i++)
		{
			if (inventory[i].productID == productID[i])
			{
				cout << "\n\nWe have a match!";
				cout << "\n\nProduct ID " << productID[i] << " matches: ";

				cout << "\nProduct name: " << inventory[i].name;
				cout << "\nProduct Description: " << inventory[i].description;
				cout << "\nProduct Price: " << inventory[i].retailPrice;
			}
			else
			{
				cout << "\n\nProduct ID " << productID[i] << " has no matches";
			}
		}

	double sum = 0;

	for (int b = 0; b < numProduct; b++)
	{
		sum += inventory[b].retailPrice;
	}

	cout << "\n\nProducts Sum: " << sum;

	double average = sum / productID.size();
	cout << "\n\nAverage = " << average;
}

void Display_Product(Product_S* inventory, int *numProduct)
{
	for (int i = 0; i < *numProduct; i++)
	{
		cout << "\nProduct information";

		cout << "\nProduct name: " << inventory[i].name;
		cout << "\nProduct ID: " << inventory[i].productID;
		cout << "\nProduct Description: " << inventory[i].description;
		cout << "\nProduct Price: " << inventory[i].retailPrice;
	}
}

void Product_IDs(vector <int>& productID)
{
	int numID;
	char moreData = 'y';
	while (moreData == 'y')
	{
		cout << "\nEnter a Product ID: ";
		cin >> numID;

		productID.push_back(numID);

		cout << "\nEnter y to continue or anything else to quit: ";
		cin >> moreData;
	}
}

void Display_IDs(vector <int>& productID)
{
	for (int i = 0; i < productID.size(); i++)
	{
		cout << "\nProduct ID #" << i + 1 << " is " << productID[i];
	}
}




