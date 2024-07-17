
/***
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c)2023 Media Design School
File Name : Board.h
Description : The header file provides the class declaration and function prototypes
             for the Battleship game implementation
Author : Smirti parajuli
Mail : smirti.parajuli@mds.ac.nz
**/

#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <string>

using namespace std;

class Board // TF: Class
{
	friend ostream& operator<<(ostream&, const Board&);
	friend istream& operator>>(istream&, Board&);
	friend istream& getline(istream&, Board&);

public:// TF: Access Specifier
	Board();// TF: Constructor
	~Board();// TF: Destructor
	void printBoard();// prints the board so user can see
	void printBoardPlayer();
	void showActualBoard();
	void initializeBoard();
	void setBoard();
	void populate(); // populates the board with * in all places.
	bool placeship(int, int, int, int, char, string, bool); 
	void checkhit(char, int);
	void theConsole(string);// the ammo and hits
	void dolinkedlist();
	void printlinkedlist();// prints linkedlist
	bool checklinkedlist();
	void setfirst();//set the first pointer for linked list
	void setlast();// set the last pointer for linked list
	void setmunitions();
	void setCoords(char, int);
	int returnhits();
	int returnammo();
	int returnmiss();
	int returnhity();
	int getBoardSize();

	struct nodeType
	{
		char x;
		int y;
		int hom;
		nodeType* link;
	};

protected:// TF: Access Specifier
	int bsizeX;//the y ultimate value of boad size
	int bsizeY;// the x ultimate value of board size

private:// TF: Access Specifier
	static const int BOARD_SIZE = 10;
	char boardArray[BOARD_SIZE][BOARD_SIZE];

	//char boardArray[10][10];
	char** hideShip;    // TF: Array
	char** showShip;	// TF: Array
	int ammo;
	int hit;
	int miss;
	string hitstr;
	char hitx;	//user input x coordinate
	int hity;	// user input y coordinate
	int playerStatus;
	nodeType* first;	//pointeror linked list
	nodeType* last;	// pointer for linked list
	nodeType* newnode;	//pointer for linked list
};
#endif
