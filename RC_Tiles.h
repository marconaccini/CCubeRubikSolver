/*H**********************************************************************
* FILENAME :        RC_Tiles.h / .c
*
* DESCRIPTION :
* 
*       Defines colors of Rubik Cube solver
*
* AUTHOR :    Naccini Marco        START DATE :    14/09/21 
*H***********************************************************************/

#ifndef RC_Tiles_h
#define RC_Tiles_h

typedef enum 
{
     Nc, // no color
     Wh, // White
     Ye, // Yellow
     Bl, // Blue
     Gn, // Green
     Or, // Orange
     Rd  // Red
} Color;

typedef Color Tile;

// Functions:
char * get_color2string // Convert a color *c* to a string
    (
    char * destStr, // string destination
    Color c         // tile color
    ); 
    
char * get_tile2string // Convert a tile *t* to a string
    (
    char * destStr, // string destination
    Tile t          // tile color
    );
    
char * get_color2stringShort  // Convert a color *c* to a string in a short versione
    (
    char * destStr,  // string destination
    Color c          // tile color
    );
    
char * get_tile2stringShort // Convert a tile *t* to a string in a short versione
    (
    char * destStr, // string destination
    Tile t           // tile color
    );

// Functions Tests:
void RC_Tiles_Test(void);

#endif