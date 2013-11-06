#include "Memory.h"

#ifdef __DEBUG__
#include<stdio.h>
#endif

int
init_memfile()
{
  short i;

  for( i = 0; i < MEMSIZE; ++i )
    theMemoryFile[i] = 0;

#ifdef __DEBUG__
  printf("init_memfile()\n");
#endif

  return 0;
}

int
store( int loc, Memory data )
{
#ifdef __DEBUG__
  printf("store()\n");
#endif

  if( ( loc > MAXLOC ) || ( loc < 0 ) )
    {
      perror("Trying to write to a location out-of-range");
      error_bit = 1;
      return 1;
    }

  theMemoryFile[loc / DBLWORD] = data;
  return 0;
}

Memory
load( int loc )
{
#ifdef __DEBUG__
  printf("load()\n");
#endif

  if( ( loc > MAXLOC ) || ( loc < 0 ) )
    {
      perror("Trying to read from location out-of-range");
      error_bit = 1;
      return 0;
    }
  else
    {
      return theMemoryFile[loc / DBLWORD];
    }
}

int
print_mem()
{
  short i;

#ifdef __DEBUG__
  printf("print_mem()\n");
#endif

  printf("MEMORY\n");

  for( i = 0; i < MEMSIZE; ++i )
    {
      if( theMemoryFile[i] != 0 )
	printf("%d %d\n", i * DBLWORD, theMemoryFile[i] );
    }

  if( i > 0 )
    printf("\n");

  return 0;
}

int
get_mem_error_bit()
{
  return error_bit;
}

void
clear_mem_error_bit()
{
  error_bit = 0;
}
