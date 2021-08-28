#include "cube.h"
#include <stdio.h>


int main(void)
{
    piece p;
    p.color[0] = 12;
    piece_define(& p, Rd, Nc, Gr);
    printf("Color of tile x of piece is: %d\n", get_piece(p, x_ax));
    printf("Color of tile y of piece is: %d\n", get_piece(p, y_ax));
    printf("Color of tile y of piece is: %d\n", get_piece(p, z_ax));
    return 0;
}