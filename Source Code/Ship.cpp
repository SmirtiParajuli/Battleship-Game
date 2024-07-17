/***
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c)2023 Media Design School
File Name : Ship.cpp
Description :this file defines a class for a ship object,with constructors to set initial values,
             member functions to manipulate and retrieve attributes, and random number generation to
             assign values to specific attributes.
Author : Smirti parajuli
Mail : smirti.parajuli@mds.ac.nz
**/

#include <cstdlib>
#include "Ship.h"

using namespace std;

Ship::Ship()
    : shipx(0), shipy((rand() % (9 - 1)) + 1),
    shipHV((rand() % (3 - 1)) + 1)
{
    size = 3;
}

Ship::Ship(int num)
    : shipx(0), shipy((rand() % (9 - 1)) + 1),
    shipHV((rand() % (3 - 1)) + 1)
{
    size = num;
}

Ship::~Ship()
{

}

int Ship::setx()
{
    shipx = ((rand() % (9 - 1)) + 1);
    return shipx;
}

int Ship::sety()
{
    shipy = ((rand() % (9 - 1)) + 1);
    return shipy;
}

int Ship::getsize()// returns the size of the ship.
{
    return size;
}

int Ship::setHV()//generates a random value for the ship and returns it.
{
    shipHV = ((rand() % (3 - 1)) + 1);
    return shipHV;
}