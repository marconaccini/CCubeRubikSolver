#include <stdio.h>
#include <string.h>
#include "RC_Coords.h"

// Fases disposition
//             ^ y_2d
//             |
//          [Or ( z)]
// [Gr (-y)][Wh ( x)][Bl (y)]
//          [Rd (-z)]
//          [Ye (-x)]
//             +---> x_2d
// where x,y,z are 3D coordinates passing faces
//
// Face coordinates:
//          ^ y_2d
//          |
// +1  [ ] [|] [ ] 
//  0 -[-]-[+]-[-]--> x_2d
// -1  [ ] [|] [ ] 
//     -1   0   1 

// *** Functions


xy_coords * coords_90rot(xy_coords * rxy, xy_coords * oxy, dir_selector d)
{
    int dir;
    
    if (d == sel_Cw_dir) dir = 1;
    else dir = -1;
    
    rxy->x2 = dir * oxy->y2;
    rxy->y2 = - dir * oxy->x2;
    
    return rxy;

}
   


//arr3coords * coords3D_xyz2arr(arr3coords * ac, xyz_coords * xyz)
//{
//    ac = (int (*)[3]) xyz;
//    return ac;
//}
//
//xyz_coords * coords3D_arr2xyz(xyz_coords * xyz, arr3coords * ac)
//{
//    xyz =  (xyz_coords *) ac;
//    return xyz;
//}