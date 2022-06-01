// Colin Reagan
// CIS 1202
// 2/21/2022
// Programming Assignment #6

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

// Void Prototypes
int menu();
void displayWinLoss(struct WinLoss location);
void displayTeam(struct Team currentTeam);
void findTeam(struct Team allTeams[], int size);
Team getTeams();

struct WinLoss 
{
    int wins;
    int losses;
};

struct Team
{
    string name;
    struct WinLoss total;
    struct WinLoss home;
    struct WinLoss away;
};

int main()
{
    int choice = 1;
    struct Team allTeams[25];
    int size = 0;

    while (true) {
        choice = menu();
        switch (choice)
        {
        case 1:
            allTeams[size] = getTeams();
            size++;
            break;
        case 2:
            for (int i = 0; i < size; i++)
            {
                displayTeam(allTeams[i]);
            }
            break;
        case 3:
            findTeam(allTeams, size);
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }

    cout << endl << endl;
    system("pause");
    return 0;
}

// Display Menu
int menu() 
{
    bool choice = true;

    while (choice) 
    {
        int choice;
        cout << "1. Enter a new team" << endl;
        cout << "2. Display all teams" << endl;
        cout << "3. Display a particular team" << endl;
        cout << "4. Exit the program" << endl;
        cin >> choice;

        if (choice == 4)
        {
            cout << "Goodbye!" << endl;
        }

        // Prevents user from entering outside of number range
        if (choice < 1 || choice > 4) 
        {
            cout << "You did not pick a correct option. Please try again." << endl;
        }
        else 
        {
            return choice;
        }
    }
}

// Ask user to input wins and losses
WinLoss getWinLoss(string location) 
{ 
    struct WinLoss input;
   
    cout << "Enter the " << location << " wins: ";
    cin >> input.wins;
    
    cout << "Enter the " << location << " losses: ";
    cin >> input.losses;
    
    return input;
}

// Displays information from previous function
void displayWinLoss(struct WinLoss location) 
{
    cout << location.wins << "-" << location.losses << endl;
}

Team getTeams()
{
    struct Team singleTeam;
    struct WinLoss homeScore, awayScore, totalScore;

    // Ask for the team name
    cout << "Team name? ";
    cin.ignore();
    getline(cin, singleTeam.name);

    // Get the HomeScore
    homeScore = getWinLoss("home");

    // Get the AwayScore
    awayScore = getWinLoss("away");

    // Calculate the total score
    totalScore.wins = homeScore.wins + awayScore.wins;
    totalScore.losses = homeScore.losses + awayScore.losses;

    singleTeam.home = homeScore;
    singleTeam.away = awayScore;
    singleTeam.total = totalScore;
    
    return singleTeam;
}

// Display Team Names
void displayTeam(struct Team currentTeam)
{
    cout << currentTeam.name << endl;
    
    cout << "Total record ";
    displayWinLoss(currentTeam.total);
    
    cout << "Home record ";
    displayWinLoss(currentTeam.home);
    
    cout << "Away record ";
    displayWinLoss(currentTeam.away);
}

// Finds the team within the system
void findTeam(struct Team allTeams[], int size) 
{
    string teamSearch;

    // Ask for the team name
    cout << "Team name? ";
    cin.ignore();
    getline(cin, teamSearch);

    // Check if the team name is within the data
    bool search = false;

    for (int i = 0; i < size; i++)
    {
        if (allTeams[i].name == teamSearch) 
        {
            search = true;
            displayTeam(allTeams[i]);
            break;
        }
    }

    // Team name is not found in search
    if (search == 0) 
    {
        cout << "Team not found." << endl;
    }
}

