#include "Register.h"

#include<stdio.h>
#include<string.h>

void
init_regs()
{
  short i;

#ifdef __DEBUG__
  printf("init_regs()\n");
#endif

  for( i = 0; i < REGFILESIZE; ++i )
    theRegisterFile[i] = 0;
}

int
set_reg( char * reg, Register data )
{
  int n;

#ifdef __DEBUG__
  printf("set_reg()\n");
#endif

  if( sscanf( reg, "R%d", &n ) != 1 )
    return 1;

  if( ( n >= REGFILESIZE ) || ( n < 0 ) )
    return 1;

  theRegisterFile[n] = data;

  return 0;
}

int
set_regi( int reg, Register data )
{
#ifdef __DEBUG__
  printf("set_regi()\n");
#endif
  
  if( ( reg >= REGFILESIZE ) || ( reg < 0 ) )
    return 1;

  theRegisterFile[reg] = data;
  return 0;
}

Register
get_reg( char * reg )
{
  int n;

#ifdef __DEBUG__
  printf("get_reg()\n");
#endif

  /* if not found */
  if( sscanf( reg, "R%d", &n ) != 1 )
    {
      perror("Attempt to access register that could not be found!");
      return 1;
    }
  else if( ( n >= REGFILESIZE ) || ( n < 0 ) )
    {
      perror("Attempt to access register that could not be found!");
      return 1;
    }
  else
    {
      return theRegisterFile[n];
    }
}

Register
get_regi( int reg )
{
#ifdef __DEBUG__
  printf("get_regi()\n");
#endif
  if( ( reg >= REGFILESIZE ) || ( reg < 0 ) )
    {
      perror("Attempt to access register that could not be found!");
      return 0;
    }
  else
    {
      return theRegisterFile[reg];
    }
}

void
print_regs()
{
  short i;
  Register val;

#ifdef __DEBUG__
  printf("print_regs()\n");
#endif

  printf("REGISTERS\n");

  for( i = 0; i < REGFILESIZE; ++i )
    {
      val = theRegisterFile[i];
      if( val != 0 )
	printf( "R%d %d\n", i, val );
    }
  if( i > 0 )
    printf("\n");
}
