/*H**********************************************************************
* FILENAME :        piece.h
*
* DESCRIPTION :
*       Manages pieces of cube
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*H*/

// Inclusioni     *******************************************************
#ifndef piece_h
#define piece_h
#endif
#include "colors.h"
#include "cube.h"

// Definizioni    *******************************************************

// Strutture dati *******************************************************

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