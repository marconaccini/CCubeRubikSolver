/*H**********************************************************************
* FILENAME :        colors.h
*
* DESCRIPTION :
*       colors.? defines and manages colors
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*H*/

// Inclusioni     *******************************************************
#ifndef colors_h
#define colors_h

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
char * color2string(char * destStr, color c);
char * color2string_short(char * destStr, color c);

#endif