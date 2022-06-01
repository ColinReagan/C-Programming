#ifndef Publication_
#define Publication_

#include <string>
#include <iostream>

using namespace std;

enum PublicationType { BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO };

class Publication_C
{
private:
	string title, publisher;
	float price;
	int year, stock, type;
	static float totalStock;
public:
	Publication_C();

	void Store_Publication(string itemTitle, string itemPublisher, float itemPrice, int itemYear, int itemStock, int itemType);
	void Display_Info();
	void Check_Out();
	void Check_In();

	int Get_Year() const;
	int Get_Stock() const;
	string Get_Title() const;
	string Get_Publisher() const;
	float Get_Price() const;
	int Get_Type() const;
	float Get_TotalStock() const;

	void Set_Year(int);
	void Set_Stock(int);
	void Set_Title(string);
	void Set_Publisher(string);
	void Set_Price(float);
	void Set_Type(int);
};
#endif
