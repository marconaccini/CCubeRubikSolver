/*H**********************************************************************
* FILENAME :        pcube.c
*
* DESCRIPTION :
*       Modello base per programmi C
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*H***********************************************************************/

// Inclusioni     *******************************************************
#include "pcube.h"
#include <string.h>

// Definizioni    *******************************************************

// Strutture dati *******************************************************

// Prototipo funzioni ***************************************************

// Implementazione funzioni *********************************************
color get_face_color(face f, int x, int y)
{
    return f.tile[x+1][y+1];
}

face * set_face_color(face * f, int x, int y, color c)
{
    f->tile[x+1][y+1] = c;
    return f;
}

//void   face_copy(face * d, face * s)
//{
//    memcpy(d, s, sizeof(face));
//}
//
//face * get_pcube_face(face * f, pcube pq, color base_color)
//{
//    * f = pq->face[(int) base_color];
//    return f;
//}
//
//void   set_pcube_face(pcube * pq, face * f)
//{
//    
//}

//face * get_cube_face(face * f, cube q, color base_color);
//
//void pcube2cube(cube * q, pcube * pq);
//void cube2pcube(pcube * pq, cube * q);

