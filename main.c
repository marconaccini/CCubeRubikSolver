#include "cube.h"
#include <stdio.h>


int main(void)
{
    // tests
    
    piece p;
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
    return 0;
}