/*H**********************************************************************
* FILENAME :        RC_Face.h / .c
*
* DESCRIPTION :
* 
*       Defines a fase of the cube
* 
*       That is a 3x3 array of tiles.
*       The axis used has range [-1, ..., +1] values in 2d (x, y) space
*
* AUTHOR :    Naccini Marco        START DATE :    14/09/21 
*H***********************************************************************/

#include "RC_Tiles.h"
#include "RC_Coords.h"
#include "RC_Elements.h"

#ifndef RC_Face_h
#define RC_Face_h

typedef struct
{
    Tile t[3][3];
} Face;

// *** Functions

Face * Face_Set_Tile(Face * f, xy_coords xy, Color c);
Color  Face_Get_Tile(Face * f, xy_coords xy);
Face * Face_FillColor(Face * f, Color c);

#endif