#include <stdio.h>
#include <string.h>

#include "RC_Cube.h"

#define X_Fw  1 // Forward  means X = +1
#define X_Md  0 // Middle  means X = 0
#define X_Bw -1 // Backward means X = -1
#define Y_Rg  1 // Backward means Y = +1
#define Y_Md  0 // Middle  means Y = 0
#define Y_Lf -1 // Backward means Y = -1
#define Z_Up  1 // Backward means Z = +1
#define Z_Md  0 // Middle  means Z = 0
#define Z_Dw -1 // Backward means Z = -1

// *** Functions
Elem * Cube_Get_elem(
 // Gives back the color of the tile of element in (x,y,z)
    Elem * e,        // destination tile
    Cube * q,         // the cube
    xyz_coords xyz // 3d coordinates of element
    )
    {
        elem_copy(e, & q->e[xyz.x3+1][xyz.y3+1][xyz.z3+1]);
        return e;
    }

 // Gives back the color of the tile of element in (x,y,z)
Cube * Cube_Set_elem(
    Cube * q,         // destination cube
    xyz_coords xyz, // 3d coordinates of element
    Elem * e         //  coming tile
    )
    {
        elem_copy(& q->e[xyz.x3+1][xyz.y3+1][xyz.z3+1], e);
        return q;
    }
    
Cube * Cube_Base(   // Fills cube data with a base cube
    Cube * q        // the cube to create
    )
    {
    // Forward layer
        Cube_Set_elem( & q, (xyz_coords *){X_Fw, Y_Md, Z_Up}, (Elem *){Wh, Nc, Or});
        Cube_Set_elem( & q, (xyz_coords *){X_Fw, Y_Rg, Z_Up}, (Elem *){Wh, Bl, Or});
        Cube_Set_elem( & q, (xyz_coords *){X_Fw, Y_Rg, Z_Md}, (Elem *){Wh, Bl, Nc});
        Cube_Set_elem( & q, (xyz_coords *){X_Fw, Y_Rg, Z_Dw}, (Elem *){Wh, Bl, Rd});
        Cube_Set_elem( & q, (xyz_coords *){X_Fw, Y_Md, Z_Dw}, (Elem *){Wh, Nc, Rd});
        Cube_Set_elem( & q, (xyz_coords *){X_Fw, Y_Lf, Z_Dw}, (Elem *){Wh, Gr, Rd});
        Cube_Set_elem( & q, (xyz_coords *){X_Fw, Y_Lf, Z_Md}, (Elem *){Wh, Gr, Nc});
        Cube_Set_elem( & q, (xyz_coords *){X_Fw, Y_Lf, Z_Up}, (Elem *){Wh, Gr, Or});
        Cube_Set_elem( & q, (xyz_coords *){X_Fw, Y_Md, Z_Md}, (Elem *){Wh, Nc, Nc});
    
    // Middle layer
        Cube_Set_elem( & q, (xyz_coords *){X_Md, Y_Md, Z_Up}, (Elem *){Nc, Nc, Or});
        Cube_Set_elem( & q, (xyz_coords *){X_Md, Y_Rg, Z_Up}, (Elem *){Nc, Bl, Or});
        Cube_Set_elem( & q, (xyz_coords *){X_Md, Y_Rg, Z_Md}, (Elem *){Nc, Bl, Nc});
        Cube_Set_elem( & q, (xyz_coords *){X_Md, Y_Rg, Z_Dw}, (Elem *){Nc, Bl, Rd});
        Cube_Set_elem( & q, (xyz_coords *){X_Md, Y_Md, Z_Dw}, (Elem *){Nc, Nc, Rd});
        Cube_Set_elem( & q, (xyz_coords *){X_Md, Y_Lf, Z_Dw}, (Elem *){Nc, Gr, Rd});
        Cube_Set_elem( & q, (xyz_coords *){X_Md, Y_Lf, Z_Md}, (Elem *){Nc, Gr, Nc});
        Cube_Set_elem( & q, (xyz_coords *){X_Md, Y_Lf, Z_Up}, (Elem *){Nc, Gr, Or});    
    
    // Backward layer
        Cube_Set_elem( & q, (xyz_coords *){X_Bw, Y_Md, Z_Up}, (Elem *){Ye, Nc, Or});
        Cube_Set_elem( & q, (xyz_coords *){X_Bw, Y_Rg, Z_Up}, (Elem *){Ye, Bl, Or});
        Cube_Set_elem( & q, (xyz_coords *){X_Bw, Y_Rg, Z_Md}, (Elem *){Ye, Bl, Nc});
        Cube_Set_elem( & q, (xyz_coords *){X_Bw, Y_Rg, Z_Dw}, (Elem *){Ye, Bl, Rd});
        Cube_Set_elem( & q, (xyz_coords *){X_Bw, Y_Md, Z_Dw}, (Elem *){Ye, Nc, Rd});
        Cube_Set_elem( & q, (xyz_coords *){X_Bw, Y_Lf, Z_Dw}, (Elem *){Ye, Gr, Rd});
        Cube_Set_elem( & q, (xyz_coords *){X_Bw, Y_Lf, Z_Md}, (Elem *){Ye, Gr, Nc});
        Cube_Set_elem( & q, (xyz_coords *){X_Bw, Y_Lf, Z_Up}, (Elem *){Ye, Gr, Or});  

    }
    

Cube * cube_rotate(
    Cube * q,           // Cube to rotate
    Face_selector fs,   // face to rotate
    dir_selector d      // direction cw/ccw
    )
{
    Elem d_elem;
    Elem s_elem;
    Cube dcube; // destination cube
    
    xy_coords d_xy;
    xy_coords s_xy;
    xyz_coords d_xyz;
    xyz_coords s_xyz;

    Cube_Copy(& dcube, & q);
    
    for (s_xy.x2 = -1; s_xy.x2 <= 1; s_xy.x2 ++)
        for (s_xy.y2 = -1; s_xy.y2 <= 1; s_xy.y2 ++)
        {

            if ((s_xy.x2 != 0) & (s_xy.y2 != 0))
            {
                coords_90rot(& d_xy, & s_xy);
                
                coords_Get_2D_from_3D(& s_xyz, & s_xy, fs);
                coords_Get_2D_from_3D(& d_xyz, & d_xy, fs);
                
                Cube_Get_elem(& s_elem, & q, s_xyz);
                elem_copy(& d_elem, & s_elem);
                elem_Rotate(& d_elem);
                Cube_Set_elem(& dcube, d_elem, d_elem);
            }
        }
            
    memcpy(q_ptr, & dcube, sizeof(cube));
    return q_ptr;
}

Cube * Cube_Rotate( // Rotates a cube with a Singmaster notation
    Cube * q,       // the cube to rotate 
    Singmaster s    // face and direction
    )
{
    switch (s)
    {
    case F_rot:
        cube_rotate(q, Wh, Cw);
        break;
    case Fp_rot:
        cube_rotate(q, Wh, CCw);
        break;
    case B_rot:
        cube_rotate(q, Ye, Cw);
        break;
    case Bp_rot:
        cube_rotate(q, Ye, CCw);
        break;
    case R_rot:
        cube_rotate(q, Bl, Cw);
        break;
    case Rp_rot:
        cube_rotate(q, Bl, CCw);
        break;
    case L_rot:
        cube_rotate(q, Gr, Cw);
        break;
    case Lp_rot:
        cube_rotate(q, Gr, CCw);
        break;
    case U_rot:
        cube_rotate(q, Or, Cw);
        break;
    case Up_rot:
        cube_rotate(q, Or, CCw);
        break;
    case D_rot:
        cube_rotate(q, Or, Cw);
        break;
    case Dp_rot:
        cube_rotate(q, Rd, CCw);
        break;
    }
    return q;
}

Cube * Cube_Copy(   // Fills cube data with a base cube
    Cube * qd,        // cube destination
    Cube * qs,        // cube source
    )
    {
    memcpy(qd, qs, sizeof(Cube));
    return qd;
    }
