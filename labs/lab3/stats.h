// header file for stats.c

// macros
#define BUFFER_SIZE 16

// typedefs
typedef struct
{
    unsigned short buf;
    unsigned int timeStamp;
} data_storage_t;

// function declarations
void Buffer( unsigned char c );
void PrintBuf( void );
