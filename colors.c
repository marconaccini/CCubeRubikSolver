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

// Definizioni    *******************************************************

// Strutture dati *******************************************************

// Prototipo funzioni ***************************************************

// Implementazione funzioni *********************************************

char * color_print(color c)
{
    static char col_str[7][10] = {"--", "White", "Yellow", "Blue", "Green","Orange", "Red"};
    return col_str[(int) c];
}

char * color_print_short(color c)
{
    static char col_str[7][2] = {"--", "Wh", "Ye", "Bl", "Gr", "Or", "Rd"};
    return col_str[(int) c];
}