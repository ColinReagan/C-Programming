// Colin Reagan
// 2/26/2022
// C++ Programming
// eNums Assignment #7

#include <iostream>
#include <iomanip>
#include <string>
#include <random>

using namespace std;

enum suits {Hearts, Diamonds, Spades, Clubs};
enum ranks {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

struct Cards_S
{
	suits suit;
	ranks rank;
};

int menu();
void createDeck(Cards_S deck[]);
void printDeck(Cards_S deck[], int SIZE);
string getCardRank(Cards_S cards);
string getCardSuit(Cards_S cards);
Cards_S dealCardOne(Cards_S deck[]);
Cards_S dealCardTwo(Cards_S deck[]);
string winner(Cards_S card1, Cards_S card2);

int main()
{
	const int SIZE = 52;
	Cards_S deck[SIZE];

	Cards_S card1;
	Cards_S card2;

	bool again = true;

	int choice = 0;

	while (again)
	{
		choice = menu();
		if (choice == 1)
		{
			createDeck(deck);
		}
		else if (choice == 2)
		{
			printDeck(deck, SIZE);
		}
		else if (choice == 3)
		{
			card1 = dealCardOne(deck);
		}
		else if (choice == 4)
		{
			card2 = dealCardTwo(deck);
		}
		else if (choice == 5)
		{
			winner(card1, card2);
		}
		
		cout << "Enter 1 to repeat, 0 to stop: " << endl;
		cin >> again;

	}

	cout << endl << endl;
	system("pause");
	return 0;
}

// Display menu
int menu()
{
	bool choice = true;

	while (choice)
	{
		int choice;
		cout << "Please select a option" << endl;
		cout << "1. Create Deck" << endl;
		cout << "2. Display The Deck" << endl;
		cout << "3. Randomly Deal Card 1" << endl;
		cout << "4. Randomly Deal Card 2" << endl;
		cout << "5. Display Winning Card" << endl;
		cin >> choice;

		// Prevents user from entering outside of number range
		if (choice < 1 || choice > 5)
		{
			cout << "You did not pick a correct option. Please try again." << endl;
		}
		else
		{
			return choice;
		}
	}
}

// Creates the deck of cards
void createDeck(Cards_S deck[])
{
	int c = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int a = 0; a < 13; a++)
		{
			if (i == 0)
			{
				deck[c].suit = Hearts;
			}
			else if (i == 1)
			{
				deck[c].suit = Diamonds;
			}
			else if (i == 2)
			{
				deck[c].suit = Spades;
			}
			else if (i == 3)
			{
				deck[c].suit = Clubs;
			}

			if (a == 0)
			{
				deck[c].rank = Two;
				c++;
			}
			else if (a == 1)
			{
				deck[c].rank = Three;
				c++;
			}
			else if (a == 2)
			{
				deck[c].rank = Four;
				c++;
			}
			else if (a == 3)
			{
				deck[c].rank = Five;
				c++;
			}
			else if (a == 4)
			{
				deck[c].rank = Six;
				c++;
			}
			else if (a == 5)
			{
				deck[c].rank = Seven;
				c++;
			}
			else if (a == 6)
			{
				deck[c].rank = Eight;
				c++;
			}
			else if (a == 7)
			{
				deck[c].rank = Nine;
				c++;
			}
			else if (a == 8)
			{
				deck[c].rank = Ten;
				c++;
			}
			else if (a == 9)
			{
				deck[c].rank = Jack;
				c++;
			}
			else if (a == 10)
			{
				deck[c].rank = Queen;
				c++;
			}
			else if (a == 11)
			{
				deck[c].rank = King;
				c++;
			}
			else if (a == 12)
			{
				deck[c].rank = Ace;
				c++;
			}
		}
	}
}

// Display the Deck
void printDeck(Cards_S deck[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << getCardRank(deck[i]) << " of " << getCardSuit(deck[i]) << endl;
	}
}

// Gets the cards rank
string getCardRank(Cards_S cards)
{
	string rank;

	if(cards.rank == 0)
	{
		rank = "Two";
	}
	else if (cards.rank == 1)
	{
		rank = "Three";
	}
	else if (cards.rank == 2)
	{
		rank = "Four";
	}
	else if (cards.rank == 3)
	{
		rank = "Five";
	}
	else if (cards.rank == 4)
	{
		rank = "Six";
	}
	else if (cards.rank == 5)
	{
		rank = "Seven";
	}
	else if (cards.rank == 6)
	{
		rank = "Eight";
	}
	else if (cards.rank == 7)
	{
		rank = "Nine";
	}
	else if (cards.rank == 8)
	{
		rank = "Ten";
	}
	else if (cards.rank == 9)
	{
		rank = "Jack";
	}
	else if (cards.rank == 10)
	{
		rank = "Queen";
	}
	else if (cards.rank == 11)
	{
		rank = "King";
	}
	else if (cards.rank == 12)
	{
		rank = "Ace";
	}
	
	return rank;
}

// Gets the cards suit
string getCardSuit(Cards_S cards)
{
	string suit;

	if (cards.suit == 0)
	{
		suit = "Hearts";
	}
	else if (cards.suit == 1)
	{
		suit = "Diamonds";
	}
	else if (cards.suit == 2)
	{
		suit = "Spades";
	}
	else if (cards.suit == 3)
	{
		suit = "Clubs";
	}
	
	return suit;
}

// Deals the first card
Cards_S dealCardOne(Cards_S deck[])
{
	int cardOneSuit, cardOneRank;
	
	cardOneSuit = static_cast<suits>(rand() % Clubs);
	cardOneRank = static_cast<ranks>(rand() % Ace);

	cout << "Your first card is " << getCardRank(deck[cardOneRank]) << " of " << getCardSuit(deck[cardOneSuit]) << endl;

	return deck[cardOneRank];
}

// Deals the second card
Cards_S dealCardTwo(Cards_S deck[])
{
	int cardTwoSuit, cardTwoRank;

	cardTwoSuit = static_cast<suits>(rand() % Clubs);
	cardTwoRank = static_cast<ranks>(rand() % Ace);

	cout << "Your second card is " << getCardRank(deck[cardTwoRank]) << " of " << getCardSuit(deck[cardTwoSuit]) << endl;

	return deck[cardTwoRank];
}


// Declares winner of the two randomly picked cards
string winner(Cards_S card1, Cards_S card2)
{
	string winner;

	if (card1.rank > card2.rank)
	{
		winner = "Card One Wins!";
		cout << winner << endl;
	}
	else if (card1.rank < card2.rank)
	{
		winner = "Card Two Wins!";
		cout << winner << endl;;
	}
	else
	{
		winner = "Tie!";
		cout << winner << endl;;
	}

	return winner;
}