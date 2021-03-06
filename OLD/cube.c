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
#include <stdio.h>
#include <string.h>
#include "cube.h"
#include "pcube.h"

// Definizioni    *******************************************************

// Dati *****************************************************************

//planarCube pC;
//cube C;

// Prototipo funzioni ***************************************************

// Implementazione funzioni *********************************************

cube * cube_piece_define(cube * q_ptr, int x, int y, int z, piece p)
{
    piece_copy(& q_ptr->piece[x+1][y+1][z+1], & p);
    return q_ptr;
}

cube * cube_AsNew(cube * q_ptr)
{
    piece t;
    
    int x,y,z,c;
    for (x = -1; x <= 1; x++)
    {
        for (y = -1; y <= 1; y++)
        {
            for (z = -1; z <= 1; z++)
            {
                for (c = 0; c <= 2; c++) 
                    q_ptr->piece[x+1][y+1][z+1].color[c] = Nc;
            }
        }
    }
    // Forward layer
    cube_piece_define(q_ptr, X_Fw, Y_Md, Z_Up, * piece_define(& t, Wh, Nc, Or) );
    cube_piece_define(q_ptr, X_Fw, Y_Rg, Z_Up, * piece_define(& t, Wh, Bl, Or) );
    cube_piece_define(q_ptr, X_Fw, Y_Rg, Z_Md, * piece_define(& t, Wh, Bl, Nc) );
    cube_piece_define(q_ptr, X_Fw, Y_Rg, Z_Dw, * piece_define(& t, Wh, Bl, Rd) );
    cube_piece_define(q_ptr, X_Fw, Y_Md, Z_Dw, * piece_define(& t, Wh, Nc, Rd) );
    cube_piece_define(q_ptr, X_Fw, Y_Lf, Z_Dw, * piece_define(& t, Wh, Gr, Rd) );
    cube_piece_define(q_ptr, X_Fw, Y_Lf, Z_Md, * piece_define(& t, Wh, Gr, Nc) );
    cube_piece_define(q_ptr, X_Fw, Y_Lf, Z_Up, * piece_define(& t, Wh, Gr, Or) );
    cube_piece_define(q_ptr, X_Fw, Y_Md, Z_Md, * piece_define(& t, Wh, Nc, Nc) );
    
    // Middle layer
    cube_piece_define(q_ptr, X_Md, Y_Md, Z_Up, * piece_define(& t, Nc, Nc, Or) );
    cube_piece_define(q_ptr, X_Md, Y_Rg, Z_Up, * piece_define(& t, Nc, Bl, Or) );
    cube_piece_define(q_ptr, X_Md, Y_Rg, Z_Md, * piece_define(& t, Nc, Bl, Nc) );
    cube_piece_define(q_ptr, X_Md, Y_Rg, Z_Dw, * piece_define(& t, Nc, Bl, Rd) );
    cube_piece_define(q_ptr, X_Md, Y_Md, Z_Dw, * piece_define(& t, Nc, Nc, Rd) );
    cube_piece_define(q_ptr, X_Md, Y_Lf, Z_Dw, * piece_define(& t, Nc, Gr, Rd) );
    cube_piece_define(q_ptr, X_Md, Y_Lf, Z_Md, * piece_define(& t, Nc, Gr, Nc) );
    cube_piece_define(q_ptr, X_Md, Y_Lf, Z_Up, * piece_define(& t, Nc, Gr, Or) );    
    
    // Backward layer
    cube_piece_define(q_ptr, X_Bw, Y_Md, Z_Up, * piece_define(& t, Ye, Nc, Or) );
    cube_piece_define(q_ptr, X_Bw, Y_Rg, Z_Up, * piece_define(& t, Ye, Bl, Or) );
    cube_piece_define(q_ptr, X_Bw, Y_Rg, Z_Md, * piece_define(& t, Ye, Bl, Nc) );
    cube_piece_define(q_ptr, X_Bw, Y_Rg, Z_Dw, * piece_define(& t, Ye, Bl, Rd) );
    cube_piece_define(q_ptr, X_Bw, Y_Md, Z_Dw, * piece_define(& t, Ye, Nc, Rd) );
    cube_piece_define(q_ptr, X_Bw, Y_Lf, Z_Dw, * piece_define(& t, Ye, Gr, Rd) );
    cube_piece_define(q_ptr, X_Bw, Y_Lf, Z_Md, * piece_define(& t, Ye, Gr, Nc) );
    cube_piece_define(q_ptr, X_Bw, Y_Lf, Z_Up, * piece_define(& t, Ye, Gr, Or) );  
    
    return q_ptr;
}

piece * get_cube_piece(piece * out_piece_ptr, cube q, int x, int y, int z)
{
    piece * q_piece_ptr;
    q_piece_ptr = & q.piece[x+1][y+1][z+1];
    piece_copy(out_piece_ptr, q_piece_ptr);
    return out_piece_ptr;
}

cube * cube_rotate(cube * q_ptr, color f, dir d)
{
    piece or_p;
    cube dcube; // destination cube
    cube_AsNew(& dcube);
    
    int c1, c2;
    
    for (c1 = -1; c1 <= 1; c1++)
    {
        for  (c2 = -1; c2 <= 1; c2++)
        {
            if ((f == Wh)) 
            {
                /* debug purpose only */
                if ((c1 == 0) && (c2 == 1))
                {
                    printf("I'm just here");
                }
                get_cube_piece(& or_p, * q_ptr, X_Fw, c1, c2);
                piece_rotate(& or_p, x_ax);
                if (d == Cw)
                { 
                    // F Rotation
                    cube_piece_define(& dcube, X_Fw, c2, - c1, or_p);
                }
                else
                {  
                    // F' Rotation
                    cube_piece_define(& dcube, X_Fw, - c2, c1, or_p);
                }              
            }   
            else if ((f == Ye))
            {   
                get_cube_piece(& or_p, * q_ptr, X_Bw, c1, c2);
                piece_rotate(& or_p, x_ax);
                if (d == Cw)
                { 
                    // B Rotation
                    cube_piece_define(& dcube, X_Bw, c2, - c1, or_p);
                } 
                else
                {
                    // B' Rotation
                    cube_piece_define(& dcube, X_Bw, - c2, c1, or_p);
                }              
            }   
            else if ((f == Bl))
            {
                get_cube_piece(& or_p, * q_ptr, c1, Y_Rg, c2);
                piece_rotate(& or_p, y_ax);
                if (d == Cw)
                { 
                    // R Rotation
                    cube_piece_define(& dcube, c2, Y_Rg, - c1, or_p);
                }
                else
                {  
                    // R' Rotation
                    cube_piece_define(& dcube, - c2, Y_Rg, c1, or_p);
                }              
            }   
            else if ((f == Gr))
            {
                get_cube_piece(& or_p, * q_ptr, c1, Y_Lf, c2);
                piece_rotate(& or_p, y_ax);
                if (d == Cw)
                {
                    // L Rotation
                    cube_piece_define(& dcube, c2, Y_Lf, - c1, or_p);
                }
                else
                {
                    // L' Rotation
                    cube_piece_define(& dcube, - c2, Y_Lf, c1, or_p);
                }              
            }  
            else if ((f == Or))
            {
                get_cube_piece(& or_p, * q_ptr, c1, c2, Z_Up);
                piece_rotate(& or_p, z_ax);
                if (d == Cw)
                {
                    // U Rotation
                    cube_piece_define(& dcube, c2, - c1, Z_Up, or_p);
                }
                else
                {
                    // U' Rotation
                    cube_piece_define(& dcube, - c2, c1, Z_Up, or_p);
                }              
            }   
            else if ((f == Gr))
            {
                get_cube_piece(& or_p, * q_ptr, c1, c2, Z_Dw);
                piece_rotate(& or_p, z_ax);
                if (d == Cw)
                {
                    // D Rotation
                    cube_piece_define(& dcube, c2, - c1, Z_Dw, or_p);
                }
                else
                {
                    // D' Rotation
                    cube_piece_define(& dcube, - c2, c1, Z_Dw, or_p);
                }              
            } 
        }
    }
    
    memcpy(q_ptr, & dcube, sizeof(cube));
    
    return q_ptr;
}

cube * cube_rotate_Singmaster (cube * q, Singmaster rt)
{
    switch (rt)
    {
    case F_rot:
        cube_rotate(q, Wh, Cw);
        break;
    case Fp_rot:
        cube_rotate(q, Wh, CCw);
        break;
    case B_rot:
        cube_rotate(q, Ye, Cw);
        break;
    case Bp_rot:
        cube_rotate(q, Ye, CCw);
        break;
    case R_rot:
        cube_rotate(q, Bl, Cw);
        break;
    case Rp_rot:
        cube_rotate(q, Bl, CCw);
        break;
    case L_rot:
        cube_rotate(q, Gr, Cw);
        break;
    case Lp_rot:
        cube_rotate(q, Gr, CCw);
        break;
    case U_rot:
        cube_rotate(q, Or, Cw);
        break;
    case Up_rot:
        cube_rotate(q, Or, CCw);
        break;
    case D_rot:
        cube_rotate(q, Or, Cw);
        break;
    case Dp_rot:
        cube_rotate(q, Rd, CCw);
        break;
    }
    return q;
}

color get_color_of_piece_of_cube_by_orientation(
    cube q,
    int piece_x, 
    int piece_y, 
    int piece_z, axis orientation)
{
    piece p;
    get_cube_piece(& p, q, piece_x, piece_y, piece_z);
    color c = p.color[(int) orientation];
    return c;
}

void cube_print(cube * q)
{
    face f;
    char clr1[10];
    char clr2[10];
    char clr3[10];
    
    get_cube_face(& f, q, Or);

    color2string_short(clr1, get_face_color(f, -1, 1));
    color2string_short(clr2, get_face_color(f,  0, 1));
    color2string_short(clr3, get_face_color(f,  1, 1));

    color2string_short(clr1, get_face_color(f, -1, 0));
    color2string_short(clr2, get_face_color(f,  0, 0));
    color2string_short(clr3, get_face_color(f,  1, 0));

    color2string_short(clr1, get_face_color(f, -1, -1));
    color2string_short(clr2, get_face_color(f,  0, -1));
    color2string_short(clr3, get_face_color(f,  1, -1));
}