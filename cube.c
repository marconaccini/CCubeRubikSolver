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

piece * get_cube_piece(piece * p_ptr, cube q, int x, int y, int z)
{
    piece * pt_ptr = & q.piece[x+1][y+1][z+1];
    piece_copy(p_ptr, pt_ptr);
    return p_ptr;
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
    return & q;
}