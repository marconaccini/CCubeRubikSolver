/*H**********************************************************************
* FILENAME :        cube.c
*
* DESCRIPTION :
*       Contiene strutture dati e metodi per la risuoluzione del cubo di
*       Rubik
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*H*/

// Inclusioni     *******************************************************
#include "NaccLib.h"
#include "cube.h"
#include <stdio.h>
#include <string.h>

// Definizioni    *******************************************************

// dati *****************************************************************

//planarCube pC;
//cube C;

// Prototipo funzioni ***************************************************

// Implementazione funzioni *********************************************
int piece_set(piece p, axis a, color c)
{
    p.color[(int) a] = c;
    return 0;
}

color get_piece(piece p, axis a)
{
    return p.color[(int) a];
}

int piece_define(piece p, color cx, color cy, color cz)
{
    p.color[x_ax] = cx;
    p.color[y_ax] = cy;
    p.color[z_ax] = cz;
    return 0;
}

/*
int piece_define(piece p, color c)
{
    COPY(p,c);
}*/
