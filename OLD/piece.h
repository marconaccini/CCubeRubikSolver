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

#include "base.h"
#include "colors.h"

// Definizioni    *******************************************************

// Strutture dati *******************************************************

// piece is 3 axis piece of cube that contains 1, 2 or 3 tiles
typedef struct piece
{
    color color[3];
} piece;

// Prototipo funzioni ***************************************************

int piece_set_axis(piece * p, axis a, color c); // set the color of the prefixed axes
color get_piece_color(piece p, axis a);
piece * piece_define(piece * p, color cx, color cy, color cz);
int piece_copy(piece * d_ptr, piece * s_ptr);
int piece_rotate(piece * p, axis a);
int piece_print(piece p);

#endif

//    // -- copy example
//    piece p;
//    piece_define(& p, Rd, Nc, Gr);
//    printf("Original p piece - step 1\n");
//    piece_print(p);
//    piece s;
//    piece_copy(& s, & p);