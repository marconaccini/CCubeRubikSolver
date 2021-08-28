#include <stdio.h>
#include "base.h"
#include "colors.h"
#include "piece.h"
#include "cube.h"

int main(void)
{
    // tests
    
    piece p;
    
    if (1==0)
    { // Test of tiles, pieces, etc
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
    
    if (1==1) // Test of cube
    {
        cube q;
        piece p;
        
        cube_AsNew(& q);
        piece_print(q.piece[2][1][2]);
        piece_print(* get_cube_piece(& p, q, X_Fw, Y_Lf, Z_Up));
    }
    
    return 0;
}