// Colin Reagan
// 4/4/2022
// C++ Programming
// Assignment #13 - Publication Class 2

#include "Publication.h"

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

// Function Prototype
int Get_Menu_Choice();
void Get_Publications(Publication_C publication[], int &numPub, int SIZE);
void Show_Publications(Publication_C publication[], int SIZE);
void Show_Titles(Publication_C publication[], int SIZE);

int main()
{
	const int SIZE = 6;
	Publication_C publication[SIZE];
	
	int numPub;

	int choice = Get_Menu_Choice();

	while (choice != 7)
	{
		if (choice == 1)
		{
			Get_Publications(publication, numPub, SIZE);
		}
		else if (choice == 2)
		{
			Show_Publications(publication, SIZE);
		}
		else if (choice == 3)
		{
			Show_Titles(publication, SIZE);
		}
		else if (choice == 4)
		{
			string titleChoice;
		}
		else if (choice == 5)
		{
			for (int i = 0; i < SIZE; i++)
			{
				publication[i].Check_Out();
				cout << "\nTitle: " << publication[i].Get_Title();
				cout << "\nNumber of copies in stock: " << publication[i].Get_Stock();
			}
		}
		else if (choice == 6)
		{
			for (int i = 0; i < SIZE; i++)
			{
				publication[i].Check_In();
				cout << "\nTitle: " << publication[i].Get_Title();
				cout << "\nNumber of copies in stock: " << publication[i].Get_Stock();
			}
		}
		choice = Get_Menu_Choice();
	}

	cout << endl << endl;
	system("pause");
	return 0;
}

// Recieves a directory and a file name.Continues to recieve input until there is either no more input, or the publications array is filled.
void Get_Publications(Publication_C publication[], int &numPub, int SIZE)
{
	numPub = 0;

	ifstream input;
	input.open("Assignment\\publications.txt");

	if (input.is_open()) 
	{
		cout << "Opened Successfully. Reading...\n";
		string title;
		string publisher;
		float price;
		int year;
		int type;
		int stock;
		
		while (getline(input, title) && numPub < SIZE) 
		{
			getline(input, publisher);
			input >> price;
			input >> year;
			input >> type;
			input >> stock;
			input.ignore(100, '\n');
			publication[numPub].Store_Publication(title, publisher, price, year, stock, type);
			numPub++;
		}
		input.close();
	}
	else
	{
		cout << "Failed to load file.\n";
	}
}

//Displays info for all publications in an array.
void Show_Publications(Publication_C publication[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		publication[i].Display_Info();
	}
}

void Show_Titles(Publication_C publication[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Title: " << publication[i].Get_Title() << endl;
	}
}

int Get_Menu_Choice()
{
	int choice;
	cout << "\n\nPlease select a option";
	cout << "\n1. Enter Publication Information";
	cout << "\n2. Display all publications";
	cout << "\n3. Show all titles";
	cout << "\n4. Find specific title";
	cout << "\n5. Check out";
	cout << "\n6. Check in";
	cout << "\n7. Exit";
	cout << "\n\nEnter menu choice: ";
	cin >> choice;
	cout << endl;
	return choice;
}
