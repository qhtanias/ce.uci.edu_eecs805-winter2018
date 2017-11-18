#include <stdio.h>
#include "stats.h"   // header file for stats.c

static unsigned short CopiedData[BUFFER_SIZE];

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

    DataCopyWithPrint( &CopiedData[0] );

    return 0;   // return without error
}

