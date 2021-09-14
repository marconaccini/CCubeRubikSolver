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
#include <stdio.h> 
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

face * set_face_colors(face * f, color * c)
{
    int x, y;
    int i = 0;
    for (x = -1; x <=1; x++)
    {
        for (y = -1; y <=1; y++)
        {
            set_face_color(f, x, y, c[i]);
            i++;
        }
    }
    
    return f;
}

void   face_copy(face * d, face * s)
{
    memcpy(d, s, sizeof(face));
}

face * get_pcube_face(face * f, pCube pq, color base_color)
{
    * f = pq.face[(int) base_color];
    return f;
}

void   set_pcube_face(pCube * pq, face f, color base_color)
{
    face_copy(& pq->face[(int) base_color], & f);
}

face * get_cube_face(face * f_pt, cube q, color base_color)
{
    int * cx;
    int * cy;
    int * cz;
    int k;
    int fx;
    int fy;
    int ox = 1;
    int oy = 1;
    int ffx;
    int ffy;
    
    axis orientation;
    
    color c;

    switch(base_color)
    {
        case Wh:
            k = X_Fw; 
            cx = & k;
            cy = & fx;
            cz = & fy;
            ox = 1;
            oy = 1;
            orientation = x_ax;
        break;

        case Ye:
            k = X_Bw; 
            cx = & k;
            cy = & fx;
            cz = & fy;
            ox = 1;
            oy = -1;
            orientation = x_ax;
        break;
        
        case Bl:
            k = Y_Rg; 
            cx = & fx;
            cy = & k;
            cz = & fy;
            ox = -1;
            oy = 1;
            orientation = y_ax;
        break;

        case Gr:
            k = Y_Lf; 
            cx = & fx;
            cy = & k;
            cz = & fy;
            ox = 1;
            oy = 1;
            orientation = y_ax;
        break;
        
        case Or:
            k = Z_Up; 
            cx = & fy;
            cy = & fx;
            cz = & k;
            ox = 1;
            oy = -1;
            orientation = z_ax;
        break;

        case Rd:
            k = Z_Dw; 
            cx = & fy;
            cy = & fx;
            cz = & k;
            ox = 1;
            oy = 1;
            orientation = z_ax;
        break;
        
        case Nc:
        break;
    }
    
    for (ffx = -1; ffx < 2; ffx++)
    {
        for (ffy = -1; ffy < 2; ffy++)
        {
            fx = ox * ffx;
            fy = oy * ffy;
            c = get_color_of_piece_of_cube_by_orientation(q, * cx, * cy , * cz, orientation);
            set_face_color(f_pt, fx, fy, c);
        }
    }
            
    return f_pt;
}

void   face_print(face f)
{
    char clr1[10];
    char clr2[10];
    char clr3[10];
    printf("The face colors are: \n");
    color2string_short(clr1, get_face_color(f, -1, 1));
    color2string_short(clr2, get_face_color(f,  0, 1));
    color2string_short(clr3, get_face_color(f,  1, 1));
    printf(" [%s][%s][%s] \n", clr1, clr2, clr3);

    printf(" [%s][%s][%s] \n",
        color2string_short(clr1, get_face_color(f, -1, 0)),
        color2string_short(clr2, get_face_color(f,  0, 0)),
        color2string_short(clr3, get_face_color(f,  1, 0))
        );
    printf(" [%s][%s][%s] \n",
        color2string_short(clr1, get_face_color(f, -1, -1)),
        color2string_short(clr2, get_face_color(f,  0, -1)),
        color2string_short(clr3, get_face_color(f,  1, -1))
        );
}

//void pcube2cube(cube * q, pCube * pq);
//void cube2pcube(pCube * pq, cube * q);

