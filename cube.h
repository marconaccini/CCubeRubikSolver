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


//#include "colors.h"
//#include "piece.h"

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

#endif



     