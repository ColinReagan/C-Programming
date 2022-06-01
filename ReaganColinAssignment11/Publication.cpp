// Colin Reagan
// 4/4/2022
// C++ Programming
// Assignment #11 - Publication Class

#include <iostream>

using namespace std;

#include "Publication.h"

float Publication_C::totalStock = 0;

Publication_C::Publication_C()
{
	title = "";
	publisher = "";
	price = 0.0;
	year = 0;
	stock = 0;
	type = 0;
}

void Publication_C::Store_Publication(string itemTitle, string itemPublisher, float itemPrice, int itemYear, int itemStock, int itemType)
{
	title = itemTitle;
	publisher = itemPublisher;
	price = itemPrice;
	year = itemYear;
	stock = itemStock;
	type = itemType;
}

int Publication_C::Get_Year() const
{
	return year;
}

int Publication_C::Get_Stock() const
{
	return stock;
}

string Publication_C::Get_Title() const
{
	return title;
}

string Publication_C::Get_Publisher() const
{
	return publisher;
}

float Publication_C::Get_Price() const
{
	return price;
}

int Publication_C::Get_Type() const
{
	return type;
}


float Publication_C::Get_TotalStock() const
{
	return totalStock;
}

void Publication_C::Set_Year(int itemYear)
{
	year = itemYear;
}

void Publication_C::Set_Stock(int itemStock)
{
	stock = itemStock;
}

void Publication_C::Set_Title(string itemTitle)
{
	title = itemTitle;
}

void Publication_C::Set_Publisher(string itemPublisher)
{
	publisher = itemPublisher;
}

void Publication_C::Set_Price(float itemPrice)
{
	price = itemPrice;
}

void Publication_C::Set_Type(int itemType)
{
	type = itemType;
}

void Publication_C::Display_Info()
{
	cout << "\nTitle: " << title;
	cout << "\nPublisher: " << publisher;
	cout << "\nYear: " << year;
	cout << "\nStock: " << stock;
	cout << "\nPrice: " << price;

	cout << "\nType: ";
	if (type == 0)
	{
		cout << "BOOK";
	}
	else if (type == 1)
	{
		cout << "MAGAZINE";
	}
	else if (type == 2)
	{
		cout << "NEWSPAPER";
	}
	else if (type == 3)
	{
		cout << "AUDIO";
	}
	else if (type == 4)
	{
		cout << "VIDEO";
	}
	else
		cout << "Invalid";
}

void Publication_C::Check_In()
{
	stock++;
	cout << "\nChecked in.";
}

void Publication_C::Check_Out()
{
	if (stock > 0)
	{
		stock--;
		cout << "\nChecked out.";
	}
}

