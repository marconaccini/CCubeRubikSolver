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
#include "cube.h"
#include <stdio.h>
#include <string.h>

// Definizioni    *******************************************************

// dati *****************************************************************

//planarCube pC;
//cube C;

// Prototipo funzioni ***************************************************
int swap(color * x_ptr, color * y_ptr);

// Implementazione funzioni *********************************************
int piece_set(piece * p_ptr, axis a, color c)
{
    p_ptr->color[(int) a] = c;
    return 0;
}

color get_piece(piece p, axis a)
{
    return p.color[(int) a];
}

int piece_define(piece * p_ptr, color cx, color cy, color cz)
{
    piece_set(p_ptr, x_ax, cx);
    piece_set(p_ptr, y_ax, cy);
    piece_set(p_ptr, z_ax, cz);

    return 0;
}

int piece_copy(piece * d_ptr, piece * s_ptr)
{
    memcpy(d_ptr, s_ptr, sizeof(piece));
    return 0;
}

int piece_rotate(piece * p, axis a)
{
    switch (a)
    {
        case x_ax:
            swap(& p->color[y_ax], & p->color[z_ax]);
        case y_ax:
            swap(& p->color[x_ax], & p->color[z_ax]);
        case z_ax:
            swap(& p->color[y_ax], & p->color[x_ax]);
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

char * color_print(color c)
{
    static char col_str[7][10] = {"--", "White", "Yellow", "Blue", "Green","Orange", "Red"};
    return col_str[(int) c];
}

char * color_print_short(color c)
{
    static char col_str[7][2] = {"--", "Wh", "Ye", "Bl", "Gr", "Or", "Rd"};
    return col_str[(int) c];
}

int piece_print(piece p)
{
    char col[10];
    strcpy(col, color_print(get_piece(p, x_ax)));
    printf("Color of tile x of piece is: %s \n", col);
    printf("Color of tile y of piece is: %s \n", color_print(get_piece(p, y_ax)));
    printf("Color of tile z of piece is: %s \n", color_print(get_piece(p, z_ax)));
    return 0;
}
