#include <stdio.h>
#include <string.h>
#include "RC_Tiles.h"

// *** Functions

// * Convert a color *c* to a string
char * get_color2string(char * destStr, Color c)
{
    char col_str[7][10] = {"--", "White", "Yellow", "Blue", "Green","Orange", "Red"};
    strcpy(destStr, col_str[(int) c]);
    return destStr;
}

 // * Convert a tile *t* to a string
char * get_tile2string(char * destStr, Tile t)
{
    return get_color2string(destStr, t);
}

 // * Convert a color *c* to a string in a short versione
char * get_color2stringShort(char * destStr, Color c)
{
    char col_str[8][6] = {"--", "Wh", "Ye", "Bl", "Gn", "Or", "Rd"};
    strcpy(destStr, col_str[(int) c]);
    return destStr; 
}

 // Convert a tile *t* to a string in a short versione
char * get_tile2stringShort(char * destStr, Tile t)
{
    return get_color2stringShort(destStr, t);
}


// *** Tests

int test_get_color2string(void)
{
    char Str_Color[20];
    get_color2string(Str_Color, Rd);
    if (strcmp(Str_Color, "Red")==0)
    {
        printf("test_get_color2string Test OK: color %s\n", Str_Color);
    }
    else
    {
        printf("test failed !");
        return -1;
    }
    return 0;
}

int test_get_tile2string(void)
{
    char Str_Color[20];
    get_tile2string(Str_Color, Wh);
    if (strcmp(Str_Color, "White")==0)
    {
        printf("test_get_tile2string Test OK: color %s\n", Str_Color);
    }
    else
    {
        printf("test failed !");
        return -1;
    }
    return 0;
}

int test_get_color2stringShort(void)
{
    char Str_Color[20];
    get_color2stringShort(Str_Color, Wh);
    if (strcmp(Str_Color, "Wh")==0)
    {
        printf("test_get_color2stringShort Test OK: color %s\n", Str_Color);
    }
    else
    {
        printf("test failed !");
        return -1;
    }
    return 0;
}

int test_get_tile2stringShort(void)
{
    char Str_Color[20];
    get_tile2stringShort(Str_Color, Gn);
    if (strcmp(Str_Color, "Gn")==0)
    {
        printf("test_get_tile2stringShort Test OK: color %s\n", Str_Color);
    }
    else
    {
        printf("test failed !");
        return -1;
    }
    return 0;
}

void RC_Tiles_Test(void)
{   
    int err = 0;
    err += test_get_color2string();
    err += test_get_tile2string();
    err += test_get_color2stringShort();
    err += test_get_tile2stringShort();
    
    if (err == 0)
    {
        printf("RC_Tiles_Test OK !\n");
    }
}