/*H**********************************************************************
* FILENAME :        pcube.h
*
* DESCRIPTION :
*       planar model of the Rubik cube
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*H*/

// Inclusioni     *******************************************************
#ifndef pcube_h
#define pcube_h

#include "base.h"
#include "cube.h"
#include "piece.h"

// Definizioni    *******************************************************

// Strutture dati *******************************************************

typedef struct
{
    color tile[3][3];
} face;

typedef struct
{
    face face[6];
} pCube;

// Prototipo funzioni ***************************************************

int Cube2planar_reset(planarCube pC);

#endif