/*H**********************************************************************
* FILENAME :        piece.h
*
* DESCRIPTION :
*       Manages pieces of cube
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*H*/

// Inclusioni     *******************************************************
#include <stdio.h>
#include <string.h>
#include "piece.h"

// Definizioni    *******************************************************

// Strutture dati *******************************************************

// Prototipo funzioni ***************************************************
int swap(color * x_ptr, color * y_ptr);

// Implementazione funzioni *********************************************
int piece_set(piece * p_ptr, axis a, color c)
{
    p_ptr->color[(int) a] = c;
    return 0;
}

color get_piece_color(piece p, axis a)
{
    return p.color[(int) a];
}

piece * piece_define(piece * p_ptr, color cx, color cy, color cz)
{
    piece_set(p_ptr, x_ax, cx);
    piece_set(p_ptr, y_ax, cy);
    piece_set(p_ptr, z_ax, cz);

    return p_ptr;
}

int piece_copy(piece * d_ptr, piece * s_ptr)
{
    memcpy(d_ptr, s_ptr, sizeof(piece));
    return 0;
}

int piece_rotate(piece * p, axis a)
{
//    color *ca;
//    color *cb;
    switch (a)
    {
        case x_ax:
//            ca = & p->color[1];
//            cb = & p->color[2];
            swap(& p->color[y_ax], & p->color[z_ax]);
            break;
        case y_ax:
            swap(& p->color[x_ax], & p->color[z_ax]);
            break;
        case z_ax:
            swap(& p->color[y_ax], & p->color[x_ax]);
            break;
    }

    return 0;
}

int swap(color * x_ptr, color * y_ptr)
{
    color s;
    s = * x_ptr;
    * x_ptr = * y_ptr;
    * y_ptr = s;
    return 0;
}

int piece_print(piece p)
{
    char clr[10];

    printf("Color of tile x of piece is: %s \n", 
        color2string(clr, get_piece_color(p, x_ax)));
    printf("Color of tile y of piece is: %s \n", 
        color2string(clr, get_piece_color(p, y_ax)));
    printf("Color of tile z of piece is: %s \n", 
        color2string(clr, get_piece_color(p, z_ax)));
    return 0;
}