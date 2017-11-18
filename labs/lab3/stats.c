#include <stdio.h>
#include <time.h>
#include "stats.h"

static unsigned short Buf[BUFFER_SIZE];

//static data_storage_t DataStorage[BUFFER_SIZE];

//
// Function to buffer data received
// 
// inputs: 
//      unsigned char c: a byte of which to add to the buffer of 16-bit data
//
// outputs: 
//      NONE
//
void Buffer( unsigned char c )
{
    static unsigned char evenByte = 1;  // a flag that toggles every byte
    static unsigned char index = 0;     // a counter to keep track of words received

    if( evenByte )
    {
        // an even byte was received
        // store it into the lower byte of the word
        Buf[index] = (unsigned short) c;
    }
    else
    {
        // an odd byte was received
        // store it into the upper byte of the word
        Buf[index] |= (unsigned short) (c << 8);
        // increment the counter
        index++;
        if( index >= BUFFER_SIZE )
        {
            // reset the counter
            index = 0;
        }
    }

    // toggle the even/odd flag
    evenByte ^= 1;
}

//
// Function to print buffered data
// 
// inputs: 
//      NONE
//
// outputs: 
//      NONE
//
void PrintBuf( void )
{
    unsigned short * pBuf = Buf;
    unsigned char index;

    for( index = 0; index < BUFFER_SIZE; index++ )
    {
        printf( "0x%4x\n", *pBuf++ );
    }
}
