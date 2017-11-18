//
// Function to reverse bits in a byte
// 
// inputs: 
//      unsigned char c: a byte of which to reverse the bits.
//
// outputs: 
//      the bit reversed byte.
//
unsigned char bit_reverse( unsigned char c )
{
    unsigned char result = c;   // to store the result

    // YOUR SOLUTION HERE

    return result;
}

//
// Function to count the number of 1-bits in a word
// 
// inputs: 
//      unsigned int x: a word of which to count the 1-bits.
//
// outputs: 
//      a word that is the count of the bits that are set to one in the input
// 
// Reference:
//      See Kernighan and Ritchie, 2nd Edition, section 2.10
//
int bitcount( unsigned int x )
{
    int b;      // to store the result

    // initialize b to zero
    // while input x has remaining 1-bits...
    // check the zeroth bit, count it, and then shift
    for( b = 0; x != 0; x >>= 1 )
    {
        // if the zeroth bit is set, count it
        if( x & 0x01 )
        {
            b++;
        }
    }

    return b;
}
