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


#include "piece.h"

/* cube is a 3x3x3 matrix of pieces */
typedef struct 
{
    piece piece[3][3][3];
} cube;

// Prototipo funzioni ***************************************************

// cube functions:
// function cube_AsNew populates base cube colors into cube q
cube * cube_AsNew(cube * q);
// function cube_piece_define populates a piece
cube * cube_piece_define(cube * q, int x, int y, int z, piece p);
piece * get_cube_piece(piece * p_ptr, cube q, int x, int y, int z);
cube * cube_rotate(cube * q, color f, dir d);
cube * cube_rotate_Singmaster (cube * q, Singmaster r);
color get_color_of_piece_of_cube_by_orientation(cube q, int piece_x, int piece_y, int piece_z, axis orientation);

void cube_print(cube * q);

#endif
     