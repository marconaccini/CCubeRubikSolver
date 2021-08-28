#include "cube.h"
#include <stdio.h>

int main(void)
{
    piece p;
    piece_define(p, Rd, Nc, Gr);
    printf("Color of tile x of piece is: %d", get_piece(p, x_ax));
    return 0;
}