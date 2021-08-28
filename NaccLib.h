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

#ifndef Pointer
#define Pointer *
#endif

#ifndef GetPointerVal
#define GetPointerVal *
#endif

#ifndef GetPointerAddr
#define GetPointerAddr *
#endif

//#ifndef MIN(X, Y)
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
//#endif

//#ifndef COPY(X, Y)
#define COPY(X, Y) memcpy(X, Y,MIN(X, Y))
// #endif

// Strutture dati *******************************************************
typedef enum {false, true} boolean;

// Prototipo funzioni ***************************************************