/*H**********************************************************************
* FILENAME :        file name
*
* DESCRIPTION :
*       Modello base per programmi C
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*H*/

// Inclusioni     *******************************************************
#ifndef base_h
#define base_h


// Definizioni    *******************************************************

// Definizioni    *******************************************************
#define X_Fw  1 // Forward  means X = +1
#define X_Md  0 // Middle  means X = 0
#define X_Bw -1 // Backward means X = -1
#define Y_Rg  1 // Backward means Y = +1
#define Y_Md  0 // Middle  means Y = 0
#define Y_Lf -1 // Backward means Y = -1
#define Z_Up  1 // Backward means Z = +1
#define Z_Md  0 // Middle  means Z = 0
#define Z_Dw -1 // Backward means Z = -1

// Strutture dati *******************************************************

/* indicates an axis */
typedef enum 
{
    x_ax, // white and yellow faces
    y_ax, // blue and green faces
    z_ax  // orange and red faces
} axis;

typedef enum 
{
    Cw, // clockwise wise
    CCw // counter clockwise wise
} dir;

#endif

// Prototipo funzioni ***************************************************

// Implementazione funzioni *********************************************