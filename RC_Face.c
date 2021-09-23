
#include "RC_Tile.h"
#include "RC_Coords.h"
#include "RC_Element.h"
#include "RC_Face.h"

// *** Functions

Face * Face_Set_Tile
    (
    Face * f,       // destination face
    xy_coords xy,   // 2D coordinates with -1, 0, +1 range values
    Color c         // color
    )
    {
        f->t[xy->x2+1][xy->y2+1] = c;
        return f;
    }
    
Color  Face_Get_Tile+
    (
    Face * f,       // destination face
    xy_coords xy    // 2D coordinates with -1, 0, +1 range values
    )
    {
        return f->t[xy->x2+1][xy->y2+1];
    }
    
Face * Face_FillColor
    (
    Face * f, // destination face
    Color c   // color
    )
    {
        int x;
        int y;
        for (x=-1; x<=1;x++)
            for (y=-1; y<=1;y++)
                f->t[x+1][y+1] = c;
        return f;
    }
    

Face * Face_copy(Face * dest, Face * src)
{
    memcpy(dest, src, sizeof(Face));
    return dest;
}