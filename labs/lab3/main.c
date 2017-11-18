#include <stdio.h>
#include "stats.h"   // header file for stats.c

//
// main function
// 
// inputs: //
// outputs: 
//      An integer for the error status (0 indicates no error).
//
int main( void )
{
    int c;  // to store the input stream

    // get characters from standard input
    while( (c = getchar()) != EOF )
    {
        Buffer( c );
    }

    PrintBuf();

    return 0;   // return without error
}

