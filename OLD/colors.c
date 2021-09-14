/*H**********************************************************************
* FILENAME :        colors.c
*
* DESCRIPTION :
*       Manage colors
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*H*/

// Inclusioni     *******************************************************
#include "colors.h"
#include <string.h>

char * color2string(char * destStr, color c)
{
    char col_str[7][10] = {"--", "White", "Yellow", "Blue", "Green","Orange", "Red"};
    strcpy(destStr, col_str[(int) c]);
    return destStr;
}

char * color2string_short(char * destStr, color c)
{
    char col_str[8][6] = {"--", "Wh", "Ye", "Bl", "Gr", "Or", "Rd"};
    strcpy(destStr, col_str[(int) c]);
    return destStr; 
}