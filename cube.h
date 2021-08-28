/*H**********************************************************************
* FILENAME :        cube.h             DESIGN REF: CCubeRubikSolver
*
* DESCRIPTION :
*       Contiene strutture dati e metodi per la risuoluzione del cubo di
*       Rubik
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*H*/
// Includes

#ifndef cube_h
#define cube_h
#endif
#include "colors.h"

// Definizioni    *******************************************************
#define X_Fw  1 // Forward  means X = +1
#define X_Bw -1 // Backward means X = -1
#define Y_Rg  1 // Backward means Y = +1
#define Y_Lf -1 // Backward means Y = -1
#define X_Up  1 // Backward means Z = +1
#define X_Dw -1 // Backward means Z = -1

// Strutture dati *******************************************************

/* indicates an axis */
typedef enum 
{
    x_ax, // white and yellow faces
    y_ax, // blue and green faces
    z_ax  // orange and red faces
} axis;

typedef enum 
{
    Cw, // clockwise wise
    CCw // counter clockwise wise
} dir;

// piece is 3 axis piece of cube that contains 1, 2 or 3 tiles
typedef struct piece
{
    color color[3];
} piece;

// Prototipo funzioni ***************************************************

int piece_set_axis(piece * p, axis a, color c); // set the color of the prefixed axes
color get_piece(piece p, axis a);
int piece_define(piece *  p, color cx, color cy, color cz);
int piece_copy(piece * d_ptr, piece * s_ptr);
int piece_rotate(piece * p, axis a);
int piece_print(piece p);




     