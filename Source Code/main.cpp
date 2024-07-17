/***
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c)2023 Media Design School
File Name : battleshipgame.h
Description :  This file implements a playable version of Battleship with some additional features 
like debug mode and a menu system. 
Author : Smirti parajuli
Mail : smirti.parajuli@mds.ac.nz
**/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <random>
#include <string>
#include <sstream>
#include <windows.h>
#include "battleshipgame.h"
#include "Board.h"
#include <ctime>

using namespace std;
HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
void whileCheck(char&);// TF: Reference
void whileGoback(char&);
int menu;

string player = "Your board\n";
string AIplayer = "Enemy's board\n";

battleshipgame abjects;
battleshipgame bbjects;

bool debugMode = false; // Define and initialize the debugMode variable // TF: Variable Type


void game(bool debugMode) // TF: Function with Default Parameter 
{
    abjects.initialize(AIplayer, debugMode);
    bbjects.initialize(player, debugMode);

    bool playerTurn = true; // Flag to track whose turn it is, true for player's turn, false for AI's turn

    while (abjects.getAmmo() > 0 && bbjects.getAmmo() > 0 && abjects.hits < 17 && bbjects.hits < 17)
    {
        if (playerTurn)
        {
            cout << endl << "Enter first letter(column), and then the number(row). Do not use space (example: C5)" << endl;
            cin.clear();
            getline(cin, abjects);

            if (abjects.hity > 0) {
                cout << "Your previous shots: " << endl;
                //linkedlist
                abjects.thelist();
                //show the ammo left and hits gotten
                abjects.theConsole(AIplayer);
                cout << abjects << endl;
            }

            playerTurn = false; // Switch to AI's turn  // TF: Variable Type
        }
        else
        {
            SetConsoleTextAttribute(l, 14);
            cout << "Please Wait for Enemy's Input...\n" << endl;
            SetConsoleTextAttribute(l, 7);
            // TF: Pseudo Random Numbe
            int randomSleep = (rand() % 1500);

            Sleep(randomSleep);
            int randomNumber = (rand() % 9) + 1;// TF: Pseudo Random Number
            int randomNumberAlpha = (rand() % 9) + 1;// TF: Pseudo Random Number

            // Map the random number to ASCII values for '1' to '10'
            char number = '0' + randomNumber;// TF: Arithmetic Operator

            // Map the random number to ASCII values for 'A' to 'J'
            char key = 'A' + randomNumberAlpha;// TF: Arithmetic Operator
            // Simulate the key press
            SetConsoleTextAttribute(l, 11);
            cout << "Enemy entered: " << key << number << "\n" << endl;// TF: Output Statement
            SetConsoleTextAttribute(l, 7);

            // Feed the key press to cin istream
            stringstream ss;
            ss << key << number;
            cin.clear();
            //cin.rdbuf(ss.rdbuf());
            // Read the key press from cin
            getline(ss, bbjects);// TF: Input Statement

            if (bbjects.hity > 0) {
                cout << "Enemy's previous shots: " << endl;// TF: Output Statement
                //linkedlist
                bbjects.thelist();
                //show the ammo left and hits gotten
                bbjects.theConsole(player);
                cout << bbjects << endl; // TF: Output Statement
            }
            else {
                cout << "Please try again" << endl;
            }

            playerTurn = true; // Switch to player's turn  // TF: Variable Type
        }
    }

    cout << endl;

    if (abjects.hits == 17) {
        SetConsoleTextAttribute(l, 10);
        cout << setfill(' ') << setw(32) << "Game is Finished" << endl;
        cout << "Congratulations, you Win! You have sunk all Enemy ships" << endl;
        SetConsoleTextAttribute(l, 7);
    }
    else if (bbjects.hits == 17) {
        SetConsoleTextAttribute(l, 14);
        cout << setfill(' ') << setw(32) << "Game is Finished" << endl;
        cout << "Very Sad captain, Enemy Win! Enemy has sunk all your ships" << endl;
        SetConsoleTextAttribute(l, 7);
    }
    else if (abjects.hits > bbjects.hits)
    {
        SetConsoleTextAttribute(l, 10);
        cout << setfill(' ') << setw(30) << "Game is Finished" << endl;
        cout << "Congratulations, you Win! Enemy has scored less than you" << endl;
        SetConsoleTextAttribute(l, 7);
    }
    else if (abjects.hits < bbjects.hits)
    {
        SetConsoleTextAttribute(l, 14);
        cout << setfill(' ') << setw(30) << "Game is Finished T_T" << endl;
        cout << "Very Sad captain, Enemy Win! Enemy has scored more than you" << endl;
        SetConsoleTextAttribute(l, 7);
    }
    else if (abjects.hits == bbjects.hits)
    {
        SetConsoleTextAttribute(l, 10);
        cout << setfill(' ') << setw(25) << "Game is Finished" << endl;
        cout << "Congratulations, you both Won! Live in Harmony" << endl;
        SetConsoleTextAttribute(l, 7);
    }
    else
    {
        SetConsoleTextAttribute(l, 14);
        cout << setfill(' ') << setw(22) << "Game is Finished" << endl;
        cout << "You Both Lost! Better luck next time" << endl;
        SetConsoleTextAttribute(l, 7);

    }
}
int main()
{
    // need in order to randomize the numbers
    srand(static_cast<unsigned int>(time(nullptr)));
    int ans = 0;
    char cont = 'y'; // Initialize cont to 'y'

    abjects.introduction();

    do
    {
        cout << "1) Start The Game\n2) Game Rules\n3) Credits\n4) Exit The Game\n5) Debug mode\n";
        cin >> menu;

        cin.clear();
        cin.ignore(10000, '\n');

        switch (menu)
        {
        case 1:
        {   game(false);
        cout << endl;
        whileCheck(cont);
        break;
        }
        case 2:
        {
            SetConsoleTextAttribute(l, 6);
            cout << "=========================" << endl;
            cout << "||BATTLESHIP GAME RULES||" << endl;
            cout << "=========================" << endl;

            SetConsoleTextAttribute(l, 7);
            cout << "\nEach game will have at least 5 ships. " << endl;
            cout << "There are 5 distinct ships out at sea. They are: " << endl;

            cout << "\nSubmarine S" << endl;
            cout << "The Submarine's size is 3 squares on the grid. " << endl;
            cout << "The submarine is stealthy and lethal." << endl;

            cout << "\nBattleship B" << endl;
            cout << "The Battleship size is 4 squares on the grid. " << endl;
            cout << "The Battleship should be easy to spot." << endl;

            cout << "\nPatrol boat P" << endl;
            cout << "The Patrol boat's size is 2 squares on the grid. " << endl;
            cout << "Patrol boat is the hardest target to hit in the game." << endl;

            cout << "\nDestroyer D" << endl;
            cout << "The Destroyer's size is 3 squares. " << endl;
            cout << "Beware of the destroyer's mighty firepower." << endl;

            cout << "\nCarrier C" << endl;
            cout << "The Carrier takes up 5 squares. " << endl;
            cout << "It is the biggest ship out at sea. " << endl;

            cout << "\nRemember, the ships' positions are either horizontal or vertical. " << endl;
            cout << "Their maneuvers are stationary." << endl;

            cout << "\n% MEANS YOU HAVE HIT SEA." << endl;
            cout << "You have 30 Ammo to hit all targets!" << endl;

            cout << "\nGood Luck, Captain!\n" << endl;
            whileGoback(cont);
            break;
        }
        case 3:
            SetConsoleTextAttribute(l, 14);
            {
                cout << "***********************************************" << endl;
                cout << "  Bachelor of Software Engineering" << endl;
                cout << "  Media Design School" << endl;
                cout << "  Auckland" << endl;
                cout << "  New Zealand" << endl;
                cout << "  Author : Smirti parajuli" << endl;
                cout << "  Mail : smirti.parajuli@mds.ac.nz" << endl;
                cout << "  Date: 13-06-2023" << endl;
                cout << "***********************************************" << endl;
                cout << "***********************************************" << endl;
                SetConsoleTextAttribute(l, 7);
            whileGoback(cont);
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        case 5:
        {   cout << "Debug mode Activated \n" << endl;
        game(true);
        cout << endl;
        whileCheck(cont);

        break;


        }
        break;
        }

    } while (cont == 'y' || cont == 'Y'); // end starting while
    system("pause");
}

void whileCheck(char& a) {
    cout << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Do you wish to do it again? Y/N" << endl;
    cin >> a;

    while (a != 'y' && a != 'Y' && a != 'n' && a != 'N') {
        cout << "Did you enter the correct response? If not, please enter your response again." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> a;
    }
}

void whileGoback(char& a)
{
    cout << "\nPress Y to go back to the main menu" << endl;
    cin >> a;

    while (a != 'y' && a != 'Y') {
        cout << "Invalid input. Please enter Y to go back!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> a;
    }
}
