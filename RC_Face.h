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


//#include "RC_Element.h"

#ifndef RC_Face_h
#define RC_Face_h

#include "RC_Tile.h"
#include "RC_Coords.h"

typedef struct
{
    Tile t[3][3];
} Face;

typedef enum
{
    sel_F_face, // forward fase = white color side with orange at the top
    sel_B_face, // backward fase = yellow color side with red at the top
    sel_R_face, // right fase = blue color side with orange at the top
    sel_L_face, // left fase = green color side with orange at the top
    sel_U_face, // up fase = orange color side with yellow at the top
    sel_D_face  // down fase = red color side with white at the top
} Face_selector;

// *** Functions

// Sets the tile of a face in a xy coordinates
Face *  Face_SetXY_Tale
    (
    Face * f, 
    xy_coords * xy, 
    Color c
    );

// Gets the tile of a face in a xy coordinates
Color  Face_Get_Tile
    (
    Face * f, 
    xy_coords * xy
    );
    
// Fills the face with a color
Face * Face_FillColor
    (
    Face * f, 
    Color c
    ); 
    
// copy data from src to dest
Face * Face_copy
    (
    Face * dest, 
    Face * src
    ); 

// Converts a 2D from cube face coordinate to a 3D coordinates using cube face color
xyz_coords * coords_Get_2D_from_3D
    (
    xyz_coords * xyz,   // destination 3D coordinates of cube (3x3x3) element
    xy_coords * xy,     // 2D coordinates of face element ... 
    Face_selector f     // ... with face f
    );

// Converts a 3D from cube face coordinate to a 2D coordinates using cube face color
xy_coords * coords_Get_3D_from_2D
    (
    xy_coords * xy,     // destination 2D coordinates of cube face 
    xyz_coords * xyz,   // 3D coordinates of cube (3x3x3) element
    Face_selector f     // ... with face f
    );
    
#endif