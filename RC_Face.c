#include "RC_Face.h"
#include <string.h>
#include <stdio.h>

Face *  Face_SetXY_Tale
    (
    Face * f, 
    xy_coords * xy, 
    Color c
    )
    {
        f->t[xy->x2+1][xy->y2+1] = c;
        return 0;
    }
    
Color  Face_Get_Tile
    (
    Face * f,       // destination face
    xy_coords * xy    // 2D coordinates with -1, 0, +1 range values
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


xyz_coords * coords_Get_2D_from_3D
    (
    xyz_coords * xyz,   // destination 3D coordinates of cube (3x3x3) element
    xy_coords * xy,     // 2D coordinates of face element ... 
    Face_selector f             // ... with color f
    )
{
    switch(f)
    {
        case sel_F_face: // looking to white fase with orange at top
        // (x3, y3, z3) = (  1, x2, y2)
            xyz->x3 =   1;
            xyz->y3 =   xy->x2;
            xyz->z3 =   xy->y2;
            break;
        case sel_B_face: // looking to yellow fase with red at top
        // (x3, y3, z3) = ( -1, x2,-y2)
            xyz->x3 = - 1;
            xyz->y3 =   xy->x2;
            xyz->z3 = - xy->y2;
            break;

        case sel_R_face: // looking to blue fase with orange at top
        // (x3, y3, z3) = (-x2,  1, y2)
            xyz->x3 = - xy->x2;
            xyz->y3 =   1;
            xyz->z3 =   xy->y2;
            break;
        case sel_L_face: // looking to green fase with orange at top
        // (x3, y3, z3) = ( x2, -1, y2)
            xyz->x3 =   xy->x2;
            xyz->y3 = - 1;
            xyz->z3 =   xy->y2;
            break;

        case sel_U_face: // looking to orange fase with yellow at top
        // (x3, y3, z3) = ( -y2, x2,  1)
            xyz->x3 = - xy->y2;
            xyz->y3 =   xy->x2;
            xyz->z3 =   1;
            break;
        case sel_D_face: // looking to red fase with white at top
        // (x3, y3, z3) = ( y2, x2, -1)
            xyz->x3 =   xy->y2;
            xyz->y3 =   xy->x2;
            xyz->z3 = - 1;
            break;
    }
    return xyz;
}


// Converts a 3D from cube face coordinate to a 2D coordinates using cube face color
xy_coords * coords_Get_3D_from_2D
    (
    xy_coords * xy,     // destination 2D coordinates of cube face 
    xyz_coords * xyz,   // 3D coordinates of cube (3x3x3) element
    Face_selector f             // for face with color f
    )
{
    if ((xyz->x3 == 0) &
        (xyz->y3 == 0) &
        (xyz->z3 == 0))
            {            
                printf("error!");
            }
        else
            {
            switch(f)
            {
                case sel_F_face: // looking to white fase with orange at top
                // (x3, y3, z3) = (  1, x2, y2)
                    xy->x2 = xyz->y3;
                    xy->y2 = xyz->z3;
                    break;
                case sel_B_face: // looking to yellow fase with red at top
                // (x3, y3, z3) = ( -1, x2,-y2)
                    xy->x2 = xyz->y3;
                    xy->y2 = -xyz->z3;
                    break;

                case sel_R_face: // looking to blue fase with orange at top
                // (x3, y3, z3) = (-x2,  1, y2)
                    xy->x2 = - xyz->x3 ;
                    xy->y2 = xyz->z3;
                    break;
                case sel_L_face: // looking to green fase with orange at top
                // (x3, y3, z3) = ( x2, -1, y2)
                    xy->x2 = xyz->x3 ;
                    xy->y2 = xyz->z3 ;
                    break;

                case sel_U_face: // looking to orange fase with yellow at top
                // (x3, y3, z3) = ( -y2, x2,  1)
                    xy->y2 = - xyz->x3;
                    xy->x2 = xyz->y3;
                    break;
                case sel_D_face: // looking to red fase with white at top
                // (x3, y3, z3) = ( y2, x2, -1)
                    xy->y2 = xyz->x3;
                    xy->x2 = xyz->y3;
                    break;
            }
            return xy;
        }
        return 0;
}
 
// Test
int RC_Coords_Test_Coords_Get_2D_from_3D(void)
{
    xyz_coords xyz;
    xyz.x3 = 0;
    xyz.y3 = 0;
    xyz.z3 = 0;
    
    xy_coords xy;
    xy.x2 = 1;
    xy.y2 = 1;
    
    coords_Get_2D_from_3D(& xyz, & xy, sel_F_face);
    
    if ((xyz.x3 == 1) &
        (xyz.y3 == 1) &
        (xyz.z3 == 1))
        {
        xy.x2 = 1;
        xy.y2 = 1;
        coords_Get_2D_from_3D(& xyz, & xy, sel_U_face);
        if ((xyz.x3 == -1) &
            (xyz.y3 == 1) &
            (xyz.z3 == 1))
            {

                xy.x2 = -1;
                xy.y2 = -1;
                coords_Get_2D_from_3D(& xyz, & xy, sel_R_face);
                if ((xyz.x3 == 1) &
                    (xyz.y3 == 1) &
                    (xyz.z3 == -1))
                    {
                        printf("Test conversion coordinates 2d -> 3d: Ok \n");
                        return 0;
                    }
            }
        }
        return -1;
}

int RC_Coords_Test_coords_Get_3D_from_2D(void)
{
    xyz_coords xyz;
    xyz.x3 = 1;
    xyz.y3 = 1;
    xyz.z3 = 1;
    
    xy_coords xy;
    xy.x2 = 0;
    xy.y2 = 0;
    
    coords_Get_3D_from_2D(& xy, & xyz, sel_F_face);
    
    if ((xy.x2 == 1) &
        (xy.y2 == 1))
        {
        coords_Get_3D_from_2D(& xy, & xyz, sel_U_face);
        if ((xy.x2 == 1) &
            (xy.y2 == -1))
            {
                coords_Get_3D_from_2D(& xy, & xyz, sel_R_face);
                if ((xy.x2 == -1) &
                    (xy.y2 == 1))
                    {
                        printf("Test conversion coordinates 3d -> 2d: Ok \n");
                        return 0;
                    }
            }
        }
        return -1;
}

void RC_Coords_Test(void)
{
    int err = 0;
    err += RC_Coords_Test_Coords_Get_2D_from_3D();
    err += RC_Coords_Test_coords_Get_3D_from_2D();
    
    if (err == 0)
    {
        printf("RC_Coords_Test OK !\n");
    }
}

