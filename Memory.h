#ifndef __MEMORY_H__
#define __MEMORY_H__

#ifndef __DEBUG__
#define __DEBUG__
#endif

#include<stdint.h>

#define MEMSIZE 125
#define WORD 4
#define DBLWORD (WORD * 2)
#define MAXLOC ((MEMSIZE-1) * DBLWORD)

typedef int32_t Memory;
typedef Memory MemoryFile[MEMSIZE];

static MemoryFile theMemoryFile;
static int error_bit = 0;

/* inialize the memory file to 0s */
int
init_memfile();

/* stores value at location in memory */
/* returns 0 on success */
int
store( int, Memory );

/* load value from location in memory */
/* returns 0 if the given memory address is out of range [0, MEMSIZE] */
Memory
load( int );

/* outputs the nonzero values in memory */
/* returns 0 on success */
int
print_mem();

int
get_mem_error_bit();

void
clear_mem_error_bit();

#endif
