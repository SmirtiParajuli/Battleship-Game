/***
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c)2023 Media Design School
File Name : Board.cpp
Description : It represents the game board and contains various functions for initializing the board,
              populating it with ships, printing the board, checking hits,
             and managing a linked list to keep track of hits and misses.
Author : Smirti parajuli
Mail : smirti.parajuli@mds.ac.nz
**/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <sstream>
#include "battleshipgame.h"
#include <windows.h>

using namespace std;

Board::Board()
    : bsizeX(0), ammo(0), first(nullptr), hideShip(nullptr), last(nullptr), bsizeY(0),
    hit(0), hity(0), hitx(0), miss(0), newnode(nullptr), showShip(nullptr), boardArray(), playerStatus()
{    // TF: Pointer Initialized
}

Board::~Board()
{
    if (hideShip != nullptr) {
        for (int row = 0; row <= bsizeY; row++)
            delete[] hideShip[row];
        delete[] hideShip;  // TF: Pointer Dereferenced
    }

    
    if (showShip != nullptr) {
        for (int row = 0; row <= bsizeY; row++)
            delete[] showShip[row];
        delete[] showShip;  // TF: Pointer Dereferenced
    }
    delete first;
    delete last;
    delete newnode;
}

void Board::initializeBoard()
{// TF: Dynamic Memory

    hideShip = new char* [bsizeY + 1];
    for (int row = 0; row <= bsizeY + 1; row++)
        hideShip[row] = new char[bsizeX + 1];

    showShip = new char* [bsizeY + 1];
    for (int row = 0; row <= bsizeY + 1; row++)
        showShip[row] = new char[bsizeX + 1];
}

void Board::populate()  //populating the board with "*"
{
    for (int row = 0; row <= bsizeY; row++)
        for (int col = 0; col <= bsizeX; col++)
            hideShip[row][col] = '*';

    for (int row = 0; row <= bsizeY; row++)
        for (int col = 0; col <= bsizeX; col++)
            showShip[row][col] = '*';
}

void Board::printBoard() // settting the game board 
{  // TF: Iteration Structure

    for (int row = 0; row <= bsizeY; row++)
    {
        if (row == 0)
        {
            cout << ' ' << ' ' << "|" ;
        }
        else if (row > 0 && row < 10)
        {
            cout << " " << row <<  "|" ;
        }
        else
        {
            cout << row << "|" ;
        }
        for (int col = 1; col <= bsizeX; col++)
        {
            if (row == 0)
            {
                cout << " " << char(64 + col) << ' '  << "|" ;
            }
            else
            {
                if (playerStatus == 1)
                {
                    cout << ' ' << showShip[row][col] << ' '  << "|" ;
                }
                else
                {
                    cout << ' '  << hideShip[row][col]  << ' '  << "|" ;
                }
            }
        }
        cout << endl;

    }
}

void Board::printBoardPlayer()   //  setting the board for player
{

    for (int row = 0; row <= bsizeY; row++)
    {
        if (row == 0)
        {
            cout << ' ' << ' ' << "|";
        }
        else if (row > 0 && row < 10)   // TF: Comparison Operator TF: Logical Operator
        {
            cout  << " " << row  << "|" ;
        }
        else
        {
            cout  << row  << "|" ;
        }
        for (int col = 1; col <= bsizeX; col++)
        {
            if (row == 0)   // TF: Comparison Operator
            {
                cout << " "  << char(64 + col) << ' ' << "|" ;
            }
            else
            {
                cout << ' ' << showShip[row][col] << ' '<< "|" ;
            }
        }
        cout << endl;

    }
}

void Board::showActualBoard()
{
    for (int row = 0; row <= bsizeY; row++)
    {
        if (row == 0)
        {
            cout << ' ' << ' ' << "|";
        }
        else if (row > 0 && row < 10)
        {
            cout << " " << row << "|";
        }
        else
        {
            cout << row << "|";
        }
        for (int col = 1; col <= bsizeX; col++)
        {
            if (row == 0)
            {
                cout << " " << char(64 + col) << ' ' << "|";
            }
            if (row > 0)
            {
                cout << ' ' << showShip[row][col] << ' ' << "|";
            }
        }
        cout << endl;
    }
}

void Board::setBoard()  // setting up the board size
{

    bsizeX = 10;
    bsizeY = 10;

}
int Board::getBoardSize()
{
    return BOARD_SIZE;

}

bool Board::placeship(int x, int y, int dir, int size, char t, string player, bool debugMode)
{
    int row, col, bsize;
    row = x;
    col = y;
    bsize = 10;
    if (player == "Your board\n" || debugMode)  // TF: Conditional Statement
    {
        playerStatus = 1;
    }
    else {
        playerStatus = 0;
    }
    if (row < 0 || row > bsize || col >= bsize)  // TF: Conditional Statement TF:Logical Operator TF: Comparison Operator
    {
        return false;
    }
    if (dir == 1)
    {
        if (row + size >= bsize)
        {
            return false;
        }
        for (int i = row; i < row + size; i++)
        {
            if (showShip[i][col] != '*')
            {
                return false;
            }
        }
        for (int i = row; i < row + size; i++)
        {
            showShip[i][col] = t;
        }
    }
    else if (dir == 2)
    {
        if (col + size >= bsize)// TF: Arithmetic Operator TF: Comparison Operator
        {
            return false;
        }
        for (int j = col; j < col + size; j++)
        {
            if (showShip[row][j] != '*')
            {
                return false;
            }
        }
        for (int j = col; j < col + size; j++)// TF: Arithmetic Operator TF: Comparison Operator
        {
            showShip[row][j] = t;
        }
    }
    return true;

}

void Board::checkhit(char x, int y)
{
    // TF: Iteration Structure
    x = toupper(x);
    if (showShip[y][static_cast<int>(x - 64)] == 'S' || showShip[y][static_cast<int>(x - 64)] == 'D' || showShip[y][static_cast<int>(x - 64)] == 'C' || showShip[y][static_cast<int>(x - 64)] == 'P' || showShip[y][static_cast<int>(x - 64)] == 'B')
    {
        hideShip[y][static_cast<int>(x - 64)] = showShip[y][static_cast<int>(x - 64)];// TF: Relational Operator
        hit++;
        ammo--;
        miss = 1;
    }
    else
    {
        hideShip[y][static_cast<int>(x - 64)] = showShip[y][static_cast<int>(x - 64)] = '%';
        ammo--;
        miss = 2;
    }
    dolinkedlist();
}

void Board::setCoords(char x, int y) {
    hitx = x;
    hity = y;

    if (static_cast<int>(hitx - 64) <= 32 + bsizeX && hity <= bsizeY) { // TF: Relational Operator
        if (checklinkedlist()) {
            checkhit(hitx, hity);
        }
        else {

            cout << "Do not wast your ammo on targets we've already hit\n" << endl;

        }
    }
    else {
        cout << "You are hitting outside of the board\n" << endl;
    }

}

istream& getline(istream& obj, Board& xxx)
{

    getline(obj, xxx.hitstr);


    for (int i = 0; i < xxx.hitstr.length(); i++) {
        if (xxx.hitstr[i] == ' ') {
            xxx.hitstr.erase(i, 1);
        }
    }
    // evaluating  if the  string  contains any characters that are not alphabets or digits.
    if (xxx.hitstr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890") > 0) {
        stringstream yy(xxx.hitstr.substr(1));
        int y = 0;
        yy >> y;
        xxx.setCoords(xxx.hitstr[0], y);

    }
    else {
        cout << "Captain, it doesn't work that way. Read the rules. ";
    }

    return obj;
}

istream& operator>>(istream& obj, Board& xxx)
{
    obj >> xxx.hitx >> xxx.hity;

    if (static_cast<int>(xxx.hitx - 64) <= 32 + xxx.bsizeX && xxx.hity <= xxx.bsizeY) {
        if (xxx.checklinkedlist()) {
            xxx.checkhit(xxx.hitx, xxx.hity);
        }
        else {
            cout << " Do not wast your ammo on targets we've already hit\n" << endl;
        }
    }
    else {
        cout << "You are hitting outside of the board\n" << endl;
    }
    return obj;
}

ostream& operator<<(ostream& obj, const Board& xxx) //updating board every time player or enemy hit in the board 
{

    for (int row = 0; row <= xxx.bsizeY; row++)
    {
        if (row == 0)
        {
            obj << ' ' << ' ' << "|";
        }
        else if (row > 0 && row < 10)
        {
            obj  << " " << row  << "|"; 
        }
        else
        {
            obj << row  << "|";
        }
        for (int col = 1; col <= xxx.bsizeX; col++)
        {
            if (row == 0)
            {
                obj << " " << char(64 + col)  << ' ' << "|" ;
            }
            else
            {
                if (xxx.playerStatus == 1)
                {
                    if (xxx.showShip[row][col] == '%')  //replacing the * with % when hit in the sea 
                    {
                        cout << ' '  << xxx.showShip[row][col] << ' ' << "|" ;
                    }
                    else
                    {
                        cout << ' '  << xxx.showShip[row][col] << ' '  << "|" ;
                    }
                }
                else {
                    if (xxx.hideShip[row][col] == '%')
                    {
                        cout << ' '  << xxx.hideShip[row][col]  << ' ' << "|";
                    }
                    else
                    {
                        cout << ' '<< xxx.hideShip[row][col]  << ' ' << "|";
                    }
                }
            }
        }
        obj << endl;
    }
    obj << "Coordinates hit: " << "(" << static_cast<char>(toupper(xxx.hitx));
    obj << "," << xxx.hity << ")" << endl;

    return obj;
}

void Board::theConsole(string player)
{
    if (player == "Your board\n")
    {
        string currentplayer = "Enemy's";  //update enemys ammo and hit
        cout << endl << endl;
        cout << player << currentplayer << " " << "Ammo: " << ammo;
        cout << setfill(' ') << setw(static_cast<long long>(bsizeX) * 2 - 1) << currentplayer << ' ' << "Hits: " << hit << endl;
    }
    else
    {
        string currentplayer = "Your";  //update players anmmo and hit 
        cout << endl << endl;
        cout << player << currentplayer << " " << "Ammo: " << ammo;
        cout << setfill(' ') << setw(static_cast<long long>(bsizeX) * 2 + 2) << currentplayer << ' ' << "Hits: " << hit << endl;
    }

}

void Board::dolinkedlist()
{
    newnode = new nodeType;

    newnode->x = toupper(hitx);
    newnode->y = hity;
    newnode->hom = miss;
    newnode->link = NULL;

    if (first == NULL)
    {
        first = newnode;
        last = newnode;
    }
    else
    {
        last->link = newnode;
        last = newnode;
    }
}

void Board::printlinkedlist()
{
    nodeType* current;

    current = first;
    while (current != NULL)
    {
        switch (current->hom)
        {
        case 1:
            cout << "Coordinates: " << "(" << current->x << ", " << current->y << ") " << "HIT" << endl;
            break;
        case 2:
            cout << "Coordinates: " << "(" << current->x << ", " << current->y << ") " << "MISS" << endl;
            break;
        }
        current = current->link;
    }

}

bool Board::checklinkedlist() {
    nodeType* current;
    current = first;
    //cout << hitx << endl;
    while (current != NULL) {
        if (current->x == toupper(hitx) && current->y == hity) {
            return false;
        }
        current = current->link;
    }
    return true;
}

void Board::setfirst()
{
    first = NULL;
}

void Board::setlast()
{
    last = NULL;
}

void Board::setmunitions()
{
    ammo = 30;
    hit = 0;
    miss = 0;
}

int Board::returnammo() // return the ammo 
{
    return ammo;
}

int Board::returnhits()// return the hits
{
    return hit;
}

int Board::returnmiss()// return the miss
{
    return miss;
}

int Board::returnhity()
{
    return hity;
}
