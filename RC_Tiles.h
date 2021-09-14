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
char * get_color2string(char * destStr, Color c); // Convert a color *c* to a string
char * get_tile2string(char * destStr, Tile t); // Convert a tile *t* to a string
char * get_color2stringShort(char * destStr, Color c); // Convert a color *c* to a string in a short versione
char * get_tile2stringShort(char * destStr, Tile t); // Convert a tile *t* to a string in a short versione

// Functions Tests:
void RC_Tiles_Test(void);

#endif