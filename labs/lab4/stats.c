#include <stdio.h>
#include <time.h>
#include "stats.h"

static unsigned short Buf[BUFFER_SIZE];

//
// Function to buffer data received using pointers
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
    static unsigned short * pBuf = Buf; // pointer to the data

    if( evenByte )
    {
        // an even byte was received
        // store it into the lower byte of the word
        *pBuf = (unsigned short) c;
    }
    else
    {
        // an odd byte was received
        // store it into the upper byte of the word
        *pBuf++ |= (unsigned short) (c << 8);
        if( pBuf >= Buf + BUFFER_SIZE )
        {
            // reset the pointer address
            pBuf = Buf;
        }
    }

    // toggle the even/odd flag
    evenByte ^= 1;
}

//
// Function to copy data from Buf to that given by a pointer argument
// 
// inputs: 
//      unsigned short * pData: a pointer to the data to copy to
//
// outputs: 
//      NONE
//
void DataCopyWithPrint( unsigned short * pData )
{
    unsigned short * pBuf = Buf;

    while( pBuf < Buf + BUFFER_SIZE )
    {
        *pData++ = *pBuf++;
        printf( "0x%4x\n", *pData );
    }
}

