#include <stdio.h>
#include <string.h>
#include "RC_Tiles.h"
#include "RC_Coords.h"
#include "RC_Elements.h"

int Swap_elem_tiles(Color * x_ptr, Color * y_ptr);

Elem * elem_Set_tile(   // defines tile color to axis
    Elem * e,           // Element e destination to be set
    axis_selector ax,   // destination axis - with axis selector 'sel_#_axis'
    Color c             // color to set
    )
    {
        switch (ax)
        {
            case sel_x_axis:
                e->x = c;
                break;
            case sel_y_axis:
                e->y = c;
                break;
            case sel_z_axis:
                e->z = c;
                break;
        }
        return e;
    }
    
Elem * elem_Empty(      // set empty element (Nc, Nc, Nc)
    Elem * e            // Element e destination to be set
    )
    {
        elem_Set_tile(e, sel_x_axis, Nc);
        elem_Set_tile(e, sel_y_axis, Nc);
        elem_Set_tile(e, sel_z_axis, Nc);
        return e;
    }

Elem * elem_Set_tiles    // defines tile color to axis
    (
    Elem * e,            // Element e destination to be set
    Color c[3]         // colors array to set
    )
    {
        elem_Set_tile(e, sel_x_axis, c[1]);
        elem_Set_tile(e, sel_y_axis, c[2]);
        elem_Set_tile(e, sel_z_axis, c[3]);
        return e;
    }
    
Color elem_Get_tile(    // get tile color of an element e at axis
    Elem * e,           // Element e 
    axis_selector ax    // axis - with axis selector 'sel_#_axis'
    )
    {
        Color c;
        switch (ax)
        {
            case sel_x_axis:
                c = e->x;
                break;
            case sel_y_axis:
                c = e->y;
                break;
            case sel_z_axis:
                c = e->z;
                break;
        }
        return c;
    }

    
Elem * elem_Rotate(    // rotates and element e by axis
    Elem * e,             // Element e 
    axis_selector ax    // rotation axis - with axis selector 'sel_#_axis'
)
    {
        switch (ax)
        {
            case sel_x_axis:
                Swap_elem_tiles(& e->y, & e->z);
                break;
            case sel_y_axis:
                Swap_elem_tiles(& e->x, & e->z);
                break;
            case sel_z_axis:
                Swap_elem_tiles(& e->y, & e->x);
                break;
        }
        return e;
    }
    

int Swap_elem_tiles(Color * x_ptr, Color * y_ptr)
{
    Color s;
    s = * x_ptr;
    * x_ptr = * y_ptr;
    * y_ptr = s;
    return 0;
}

int RC_Elements_Test_emptyElem(void)
{
    Elem e;
    elem_Empty(& e);
    if ((e.x == Nc) &
        (e.y == Nc) &
        (e.z == Nc))
        {
            printf("RC_Elements_Test_emptyElem Passed Ok \n");
            return 0;
        }
    return -1;
}

int RC_Elements_Test_elem_Set_tile(void)
{
    Elem e;
    elem_Empty(& e);
    elem_Set_tile(& e, sel_x_axis, Rd);
    elem_Set_tile(& e, sel_z_axis, Gn);
    if ((e.x == Rd) &
        (e.y == Nc) &
        (e.z == Gn))
        {
            printf("RC_Elements_Test_elem_Set_tile Passed Ok \n");
            return 0;
        }
    return -1;
}

// Test
void RC_Elements_Test(void)
{
    int err = 0;
    err += RC_Elements_Test_emptyElem();
    err += RC_Elements_Test_elem_Set_tile();
    
    if (err == 0)
    {
        printf("RC_Elements_Test OK !\n");
    }
}