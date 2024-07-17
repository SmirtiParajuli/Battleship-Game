/***
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c)2023 Media Design School
File Name : Ship.h
Description :The header file provides the class declaration and function prototypes
             for the Board implementation
Author : Smirti parajuli
Mail : smirti.parajuli@mds.ac.nz
**/



#pragma once
#pragma once

#ifndef SHIP_H
#define SHIP_H

class Ship
{

public:

    Ship();
    Ship(int);//contructore with paramets, sets ships to a certain size
    ~Ship();
    int setx();// randomize the x coordinate.
    int sety();//randomize the y coordinate.
    int getsize();
    int setHV();//randomize number for either vertical or horizontal placing of ship

private:
    int shipx;//ship x coordinate
    int shipy;   //ship y coordinate
    int size;   // ship size
    int shipHV;         // ship either horizontal or vertical
};
#endif // SHIP_H
