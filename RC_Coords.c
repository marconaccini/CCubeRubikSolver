#include <stdio.h>
#include <string.h>
#include "RC_Tiles.h"
#include "RC_Coords.h"

// *** Functions
arr3coords * coords3D_xyz2arr(arr3coords * ac, xyz_coords * xyz)
{
    ac = (int (*)[3]) xyz;
    return ac;
}

xyz_coords * coords3D_arr2xyz(xyz_coords * xyz, arr3coords * ac)
{
    xyz =  (xyz_coords *) ac;
    return xyz;
}

xyz_coords * coords_2D3D(xyz_coords * xyz, xy_coords * xy, Color f)
{
    switch(f)
    {
        case Wh:
            xyz->x3 =   1;
            xyz->y3 =   xy->x2;
            xyz->z3 =   xy->y2;
            break;
        case Ye:
            xyz->x3 = - 1;
            xyz->y3 =   xy->x2;
            xyz->z3 = - xy->y2;
            break;
    }
    return xyz;
}
