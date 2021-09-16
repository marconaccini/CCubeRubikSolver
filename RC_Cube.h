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

#include "RC_Tiles.h"
#include "RC_Coords.h"
#include "RC_Elements.h"

#ifndef RC_Axis_h
#define RC_Axis_h

typedef struct
{
    Elem e[3][3][3];
} Cube;

// *** Functions

Cube * Cube_Base(Cube * q);
Cube * Cube_Rotate(Cube * q, Singmaster s);

#endif