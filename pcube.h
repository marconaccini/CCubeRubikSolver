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
    //     [Or]
    // [Gr][Wh][Bl]
    //     [Rd]
    //     [Ye]
    face face[6];
} pCube;

// Prototipo funzioni ***************************************************
color  get_face_color(face f, int x, int y);
face * set_face_color(face * f, int x, int y, color c);
//void   face_copy(face * d, face * s);
//
//face * get_pcube_face(face * f, pcube q, color base_color);
//void   set_pcube_face(pcube * pq, face * f);
//
//face * get_cube_face(face * f, cube q, color base_color);
//
//void pcube2cube(cube * q, pcube * pq);
//void cube2pcube(pcube * pq, cube * q);

#endif