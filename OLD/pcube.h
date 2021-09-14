/*H**********************************************************************
* FILENAME :        pcube.h
*
* DESCRIPTION :
*       planar model of the Rubik cube
*       
*       the *piece* object is an element of the cube
*       with 1, 2 or 3 colors
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

typedef enum {false, true} boolean;

// Strutture dati *******************************************************

typedef struct
{
    color tile[3][3];
} face;

typedef struct
{
//       ^ y
//       |
//     [Or]
// [Gr][Wh][Bl]
//     [Rd]
//     [Ye]
//       ----> x
    
    face face[6];
} pCube;

// Prototipo funzioni ***************************************************
color  get_face_color(face f, int x, int y);
face * set_face_color(face * f, int x, int y, color c);
void   face_copy(face * d, face * s);
face * set_face_colors(face * f, color * c);
void   face_print(face f);

face * get_pcube_face(face * f, pCube q, color base_color);
void   set_pcube_face(pCube * pq, face f, color base_color);

face * get_cube_face(face * f, cube q, color base_color);

//void pcube2cube(cube * q, pCube * pq);
//void cube2pcube(pCube * pq, cube * q);

#endif