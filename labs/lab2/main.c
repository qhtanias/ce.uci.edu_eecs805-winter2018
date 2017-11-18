#include <stdio.h>
#include "bits.h"   // header file for bits.c

//
// main function
// 
// inputs: 
//      None.
//
// outputs: 
//      An integer for the error status (0 indicates no error).
//
int main( void )
{
    int c;  // to store the input stream

    // get characters from standard input
    while( (c = getchar()) != EOF )
    {
        putchar( bit_reverse(c) );
    }

    return 0;   // return without error
}
