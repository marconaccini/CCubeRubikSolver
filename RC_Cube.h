///*H**********************************************************************
//* FILENAME :        RC_Cube.h / .c
//*
//* DESCRIPTION :
//* 
//*       Defines cube structure
//* 
//*       That is a 3x3x3 array of elements.
//*       The axis used has range [-1, ..., +1] values in 3d (x, y, z) space
//*       The element (0,0,0) is not used and it is a  {Nc, Nc, Nc} element
//* 
//*       The base cube is the cube with the elements at their place
//*
//* AUTHOR :    Naccini Marco        START DATE :    14/09/21 
//*H***********************************************************************/

#ifndef RC_Cube_h
#define RC_Cube_h

#include "RC_Tile.h"
#include "RC_Coords.h"
#include "RC_Element.h"

typedef struct
{
    Elem e[3][3][3];
} Cube;

// *** Functions

Cube * Cube_Base(   // Fills cube data with a base cube
    Cube * q        // the cube to create
    );

Cube * Cube_Copy(   // Fills cube data with a base cube
    Cube * qd,        // cube destination
    Cube * qs         // cube source
    );
    
Cube * Cube_Rotate( // Rotates a cube with a Singmaster notation
    Cube * q,       // the cube to rotate 
    Singmaster s    // face and direction
    );

#endif