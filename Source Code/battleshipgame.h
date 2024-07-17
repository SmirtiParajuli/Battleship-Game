/***
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c)2023 Media Design School
File Name : battleshipgame.h
Description :The header file provides the class declaration and function prototypes
             for the Battleship game implementation
Author : Smirti parajuli
Mail : smirti.parajuli@mds.ac.nz
**/

#ifndef BATTLESHIPGAME_H
#define BATTLESHIPGAME_H

#include "Board.h"
#include "Ship.h"

using namespace std;

class battleshipgame
{
	friend istream& operator>>(istream&, battleshipgame&);// overloaded operator
	friend istream& getline(istream&, battleshipgame&);
	friend ostream& operator<<(ostream&, const battleshipgame&);//overloaded operator


public:
	battleshipgame();// TF:contructor
	~battleshipgame();// TF: destructor
	void introduction() const;//introduction. calls intro of board to give rules of the game
	void initialize(string, bool);// initialize... cals various functions from board to initialize ship size, ammo, hits, level, and board.
	void theConsole(string);// shows the ammo available and hits accomplished
	void thelist();//linkedlist... adds each coordinate entered and whether hit or miss..
	int hits;// number of hits user has accomplished
	int ammo;//number of ammo or retrys user has remaining.
	int hity;
	int menu;
	int getAmmo() const {
		return ammo;
	}
	int getHits() const {
		return hits;
	}


private:  
	Board aiBoard;// TF: Class Instance
	Board theBoard;//composition the board.
	Ship Submarine;//composition ship... declare a submarine of type ship
	Ship Destroyer;// same as above, of type ship
	Ship Carrier;// same as above, of type ship
	Ship Battleship;// TF: Class Instance
	Ship PatrolBoat;// TF: Class Instance

	bool debugMode;
};
#endif // BATTLESHIPGAME_H