/*H**********************************************************************
* FILENAME :        RC_Elements.h / .c
*
* DESCRIPTION :
* 
*       Single cube element e(x,y,z) with 0, 1, 2 or 3 tiles
*
* AUTHOR :    Naccini Marco        START DATE :    14/09/21 
*H***********************************************************************/
#include "RC_Tiles.h"
#include "RC_Coords.h"

#ifndef RC_Elements_h
#define RC_Elements_h

typedef struct 
{
    Tile x;
    Tile y;
    Tile z;
} Elem;

Elem * elem_Empty      // set empty element (Nc, Nc, Nc)
    (
    Elem * e           // Element e destination to be set
    );

Elem * elem_Set_tile(   // defines tile color to axis
    Elem * e,           // Element e destination to be set
    axis_selector ax,   // destination axis - with axis selector 'sel_#_axis'
    Color c             // color to set
    );

Elem * elem_Set_tiles(   // defines tile color to axis
    Elem * e,            // Element e destination to be set
    Color c[3]         // colors array to set
    );
    
Color elem_Get_tile(    // get tile color of an element e at axis
    Elem * e,             // Element e 
    axis_selector ax    // axis - with axis selector 'sel_#_axis'
    );
    
Elem * elem_Rotate(     // rotates and element e by axis
    Elem * e,           // Element e 
    axis_selector ax    // rotation axis - with axis selector 'sel_#_axis'
);

// Test
void RC_Elements_Test(void);

#endif