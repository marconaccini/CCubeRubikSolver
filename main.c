#include <stdio.h>
#include "base.h"
#include "colors.h"
#include "piece.h"
#include "cube.h"

void Test1_PieceCreate(void);
void Test2_CubeCreate(void);
void Test3_FaceRotate(void);

int main(void)
{
 
    // Test1_PieceCreate();
    // Test2_CubeCreate();  
    Test3_FaceRotate();
    
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
    cube_AsNew(& q);
    printf("Piece in position (X_Fw, Y_Md, Z_Up) before rotation\n");
    piece_print(* get_cube_piece(& p, q, X_Fw, Y_Md, Z_Up));
    cube_rotate(& q, Wh, Cw);
    printf("Piece in position (X_Fw, Y_Md, Z_Up) after rotation\n");
    piece_print(* get_cube_piece(& p, q, X_Fw, Y_Md, Z_Up));
}