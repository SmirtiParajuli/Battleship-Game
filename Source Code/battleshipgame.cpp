#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "battleshipgame.h"
#include <windows.h>

using namespace std;
int sent = 1;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

battleshipgame::battleshipgame()
    : hits(0), Destroyer(3), Carrier(5), PatrolBoat(2), Battleship(4), Submarine(3), hity(0),
    ammo(0), menu(), debugMode(false)
{
}

battleshipgame::~battleshipgame()
{
}

void battleshipgame::introduction() const
{
    //boardGame::introduction();
    SetConsoleTextAttribute(h, 6);
    cout << "\n                                    || Welcome To ||\n" << endl;
    SetConsoleTextAttribute(h, 3);
    cout << "      $$$$$      $$$    $$$$$$  $$$$$$  $$       $$$$$$$   $$$$$   $$   $$  $$$$  $$$$$$" << endl;
    cout << "      $$  $$    $$ $$     $$      $$    $$       $$       $$   $$  $$   $$   $$   $$   $$" << endl;
    cout << "      $$$$$    $$   $$    $$      $$    $$       $$$$$     $$$     $$$$$$$   $$   $$   $$" << endl;
    cout << "      $$   $$  $$$$$$$    $$      $$    $$       $$          $$$   $$   $$   $$   $$$$$$" << endl;
    cout << "      $$   $$  $$   $$    $$      $$    $$       $$       $$   $$  $$   $$   $$   $$" << endl;
    cout << "      $$$$$$   $$   $$    $$      $$    $$$$$$$  $$$$$$$   $$$$$   $$   $$  $$$$  $$\n" << endl;
    SetConsoleTextAttribute(h, 7);
}

void battleshipgame::initialize(string player, bool debugMode)
{
    theBoard.setBoard();
    theBoard.initializeBoard();
    theBoard.populate();
    theBoard.setmunitions(); // resets the tries and hits or sets them to their regular numbers. hits=0, ammo=1


    while (sent != 0)
    {
        if (theBoard.placeship(Carrier.setx(), Carrier.sety(), Carrier.setHV(), Carrier.getsize(), 'C', player, debugMode))
            sent = 0;
    }
    sent = 1;

    while (sent != 0)
    {
        if (theBoard.placeship(Submarine.setx(), Submarine.sety(), Submarine.setHV(), Submarine.getsize(), 'S', player, debugMode))
            sent = 0;
    }
    sent = 1;

    while (sent != 0)
    {
        if (theBoard.placeship(Destroyer.setx(), Destroyer.sety(), Destroyer.setHV(), Destroyer.getsize(), 'D', player, debugMode))
            sent = 0;
    }
    sent = 1;
    while (sent != 0)
    {
        if (theBoard.placeship(Battleship.setx(), Battleship.sety(), Battleship.setHV(), Battleship.getsize(), 'B', player, debugMode))
            sent = 0;
    }
    sent = 1;
    while (sent != 0)
    {
        if (theBoard.placeship(PatrolBoat.setx(), PatrolBoat.sety(), PatrolBoat.setHV(), PatrolBoat.getsize(), 'P', player, debugMode))
            sent = 0;
    }
    sent = 1;
    theConsole(player);
    if (player == "Your board\n")
    {
        theBoard.printBoardPlayer();
    }
    else
    {
        theBoard.printBoard();
        //theBoard.showActualBoard();
    }
    theBoard.setfirst();
    theBoard.setlast();

}

void battleshipgame::theConsole(string player)
{
    hits = theBoard.returnhits();
    ammo = theBoard.returnammo();
    theBoard.theConsole(player);
}


istream& getline(istream& obj, battleshipgame& thisclass)
{
    getline(obj, thisclass.theBoard);
    thisclass.hity = thisclass.theBoard.returnhity();
    return obj;
}

istream& operator>>(istream& obj, battleshipgame& thisclass)
{
    obj >> thisclass.theBoard;
    return obj;
}

ostream& operator<<(ostream& objj, const battleshipgame& thisclass)
{
    objj << thisclass.theBoard;
    return objj;
}

void battleshipgame::thelist()
{
    theBoard.printlinkedlist();
}