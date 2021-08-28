/***********************************************************************
* FILENAME :        NaccLib.h
*
* DESCRIPTION :
*       Include varie definizioni utili a me
*
* AUTHOR :    Naccini Marco        START DATE :    28/08/21 
*/

// Inclusioni     *******************************************************


// Definizioni    *******************************************************

#if !defined NaccLib_h
#define Pointer *
#define GetPointerVal *
#define GetPointerAddr &
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define COPY(X, Y) memcpy(X, Y,MIN(X, Y))
#endif

// Prototipo funzioni ***************************************************