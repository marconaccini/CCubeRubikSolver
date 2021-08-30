/*H**********************************************************************
* FILENAME :        main.c
*
* DESCRIPTION :
*       main and test base for 
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*H***********************************************************************/

#include <stdio.h>
#include "base.h"
#include "colors.h"
#include "piece.h"
#include "cube.h"
#include "pcube.h"

void Test1_PieceCreate(void);
void Test2_CubeCreate(void);
void Test3_FaceRotate(void);
void Test4_Face(void);

int main(void)
{
 
    // Test1_PieceCreate();
    // Test2_CubeCreate();  
    // Test3_FaceRotate();
    Test4_Face();
    
    return 0;
}

void Test1_PieceCreate(void)
{
   
    piece p;
    
    // Test of tiles, pieces, etc
    p.color[0] = 12;
    piece_define(& p, Rd, Nc, Gr);
    printf("Original p piece - step 1\n");
    piece_print(p);

    piece s;
    piece_copy(& s, & p);
    
    printf("s piece copied from p - step 2\n");
    piece_print(s);
    
    piece_rotate(& s, x_ax);
    printf("s piece rotated - step 3\n");
    piece_print(s);
    
}

void Test2_CubeCreate(void )
{
    cube q;
    piece p;
    
    cube_AsNew(& q);
    piece_print(q.piece[2][1][2]);
    piece_print(* get_cube_piece(& p, q, X_Fw, Y_Lf, Z_Up));
}

void Test3_FaceRotate()
{
    cube q;
    piece p;
    
    // Cube creation
    cube_AsNew(& q);
    printf("Piece in position (X_Fw, Y_Md, Z_Up) before rotation\n");
    piece_print(* get_cube_piece(& p, q, X_Fw, Y_Md, Z_Up));
    
    // Cube white face rotation clockwise
    cube_rotate(& q, Wh, Cw);
    printf("Piece in position (X_Fw, Y_Md, Z_Up) after rotation\n");
    piece_print(* get_cube_piece(& p, q, X_Fw, Y_Md, Z_Up));
    
    // Cube F' Singmaster rotation 
    cube_rotate_Singmaster(& q, Fp_rot);
    printf("Piece in position (X_Fw, Y_Md, Z_Up) after F Singmaster rotation\n");
    piece_print(* get_cube_piece(& p, q, X_Fw, Y_Md, Z_Up));
}

void Test4_Face(void)
{
    face f;
    set_face_color(& f, -1,  1, Wh);
    set_face_color(& f,  0,  0, Rd);
    printf("Color of tile -1, 1 of face is %s \n", color_print( get_face_color(f, -1, 1)));
    printf("Color of tile  0, 0 of face is %s \n", color_print( get_face_color(f, 0, 0)));
    face f2;
    face_copy(& f2, & f);
    printf("Color of tile  0, 0 of face 2 is %s \n", color_print( get_face_color(f2, 0, 0)));
}