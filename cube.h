/*H**********************************************************************
* FILENAME :        cube.h             DESIGN REF: CCubeRubikSolver
*
* DESCRIPTION :
*       Contiene strutture dati e metodi per la risuoluzione del cubo di
*       Rubik
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*H*/
// Definizioni    *******************************************************
#define X_Fw  1 // Forward  means X = +1
#define X_Bw -1 // Backward means X = -1
#define Y_Rg  1 // Backward means Y = +1
#define Y_Lf -1 // Backward means Y = -1
#define X_Up  1 // Backward means Z = +1
#define X_Dw -1 // Backward means Z = -1

// Strutture dati *******************************************************

/* tile: tile color*/
typedef enum {
     Nc, // non - colore
     Wh, // Bianco
     Ye, // Giallo
     Bl, // Blue
     Gr, // Green
     Or, // Arancione
     Rd  // Red
} tile;

/* indicates an axis */
typedef enum 
{
    x,
    y,
    z
}
axis;

/* piece is 3 axis piece of cube that contains 1, 2 or 3 tiles*/
typedef tile piece[3];
// piece functions
int piece_define(piece p, X_col, Y_col, Z_col);
int piece_copy(piece d, piece s);
int piece_rotate(piece p, axis a);

     

     