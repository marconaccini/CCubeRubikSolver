/*H**********************************************************************
* FILENAME :        RC_Coords.h / .c
*
* DESCRIPTION :
* 
*       Defines axis selectors
*
* AUTHOR :    Naccini Marco        START DATE :    14/09/21 
*H***********************************************************************/
//#include "RC_Tile.h"

#ifndef RC_Axis_h
#define RC_Axis_h

/* rappresents x,y,z axis selector*/
typedef enum 
{
    sel_x_axis, // white and yellow faces
    sel_y_axis, // blue and green faces
    sel_z_axis  // orange and red faces
} axis_selector;

/* rappresents rotation cw/ccw selector*/
typedef enum 
{
    sel_Cw_dir, // clockwise wise
    sel_CCw_dir // counter clockwise wise
} dir_selector;

/* rappresents Singmaster selector*/
typedef enum
{
    F_rot,
    Fp_rot,
    B_rot,
    Bp_rot,
    
    L_rot,
    Lp_rot,
    R_rot,
    Rp_rot,
    
    U_rot,
    Up_rot,
    D_rot,
    Dp_rot,
} Singmaster; 

// Cube coordinates in array form
typedef int arr3coords[3];

// Cube coordinates in struct form
typedef struct 
{
    int x3;
    int y3;
    int z3;
} xyz_coords;

// face coordinates in array form
typedef int arr2coords[2];

// face coordinates in struct form
typedef struct 
{
    int x2;
    int y2;
} xy_coords;

// *** Functions

xy_coords * coords_90rot(xy_coords * rxy, xy_coords * oxy, dir_selector d);

// Test
void RC_Coords_Test(void);

#endif

// Converts 3D coordinates from struct to asrray
// arr3coords * coords3D_xyz2arr(arr3coords * ac, xyz_coords * xyz);
// Converts 3D coordinates from array to struct
// xyz_coords * coords3D_arr2xyz(xyz_coords * xyz, arr3coords * ac);