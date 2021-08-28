/*H**********************************************************************
* FILENAME :        colors.h
*
* DESCRIPTION :
*       Manage colors
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*H*/

// Inclusioni     *******************************************************
#ifndef colors_h
#define colors_h
#endif

// Definizioni    *******************************************************

/* color: colors of cube*/
typedef enum 
{
     Nc, // no color
     Wh, // White
     Ye, // Yellow
     Bl, // Blue
     Gr, // Green
     Or, // Orange
     Rd  // Red
} color;


// Strutture dati *******************************************************

// Prototipo funzioni ***************************************************
char * color_print(color c);
char * color_print_short(color c);
