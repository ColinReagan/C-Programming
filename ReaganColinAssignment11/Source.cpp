// Colin Reagan
// 4/4/2022
// C++ Programming
// Assignment #11 - Publication Class

/* #include "Publication.h"

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

// Function Prototype
void Get_Publication_Info(Publication& item);

// Driver Test
int main()
{
	Publication item;
	
	Get_Publication_Info(item);
	item.Check_Out();
	cout << "\nTitle: " << item.Get_Title();
	cout << "\nNumber of copies in stock: " << item.Get_Stock();
	item.Check_In();
	cout << "\nTitle: " << item.Get_Title();
	cout << "\nNumber of copies in stock: " << item.Get_Stock();

	cout << endl << endl;
	system("pause");
	return 0;
}

// Function to enter item details then proceed to store it
void Get_Publication_Info(Publication& item)
{
	string title, publisher;
	float price;
	int year, stock;
	PublicationType type;

	cout << "Enter item details here";
	cout << "\nWhat is the title of the item? ";
	getline(cin, title);
	cout << "Items publisher: ";
	getline(cin, publisher);

	int selection;
	cout << "\nSelect which type of item this is: ";
	cout << "\n1. Book";
	cout << "\n2. Magazine";
	cout << "\n3. Newspaper";
	cout << "\n4. Audio";
	cout << "\n5. Video";
	cout << "\nEnter Selection: ";
	cin >> selection;
	type = static_cast<PublicationType>(selection - 1);

	cout << "\nItems price: $";
	cin >> price;
	cout << "Items release year: ";
	cin >> year;
	cout << "Copies in stock: ";
	cin >> stock;
	item.Store_Publication(title, publisher, price, year, stock, type);
}

*/


