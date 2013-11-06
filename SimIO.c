#include "SimIO.h"

#ifdef __DEBUG__
#include<stdio.h>
#endif

/**
 * Assumes line holds a valid c-string
 */
int
read_register_section( char * line )
{
  char reg[MAX_STR_LEN];
  int value;

#ifdef __DEBUG__
  printf("read_register_section(): %s", line );
#endif

  if( sscanf( line, "%s %d\n", reg, &value ) != 2 )
    {
      perror("Unable to read line");
      return 1;
    }
  else
    {
      return set_reg( reg, value );
    }
}

/**
 * Assumes line holds a valid c-string
 */
int
read_memory_section( char * line )
{
  int mem;
  int value;

#ifdef __DEBUG__
  printf("read_memory_section(): %s", line );
#endif

  /* TODO */
  if( sscanf( line, "%d %d\n", &mem, &value ) != 2 )
    {
      perror( "Unable to read line" );
      return 1;
    }
  else
    {
      return store( mem, value );
    }
}

/**
 * Assumes line holds a valid c-string
 */
struct instmem *
read_code_section( char * line )
{
  char cmd[MAX_STR_LEN];

#ifdef __DEBUG__
  printf("read_code_section(): %s", line );
#endif

  /* TODO */
  if( 1 != sscanf( line, "%s\n", cmd) )
    {
      perror("malformed code");
      return NULL;
    }

  if( strcmp( cmd, "LD" ) == 0 )
    {
      /* LD */
      return create_ld( cmd );
    }
  else if( strcmp( cmd, "DADD" ) == 0 )
    {
      /* DADD */
      return create_dadd( cmd );
    }
  else if( strcmp( cmd, "SUB" ) == 0 )
    {
      /* SUB */
      return create_sub( cmd );
    }
  else if( strcmp( cmd, "SD" ) == 0 )
    {
      /* SD */
      return create_sd( cmd );
    }
  else if( strcmp( cmd, "BNEZ" ) == 0 ) 
    {
      /* BNEZ */
      /* compute address in ID */
      /* check condition in EX */
      return create_bnez( cmd );
    }
  else
    {
      /* branch label */
      printf("jump label: %s\n", cmd);
      return NULL;
    }
}

int
read_input( char * file )
{
#ifdef __DEBUG__
  printf("read_input()\n");
#endif

  /* TODO */
  pFile = fopen( file, "r" );

  if( pFile == NULL )
    return (file_read = 0);


  while(! feof( pFile ) )
    {
      read();
    }

#ifdef __DEBUG__
  print_regs();
  print_mem();
#endif

  return (file_read = 1);
}

void
close_input()
{
  if( file_read )
    fclose( pFile );

  file_read = 0;
}

void
read()
{
  char line[MAX_STR_LEN];

  fgets( line, MAX_STR_LEN, pFile );

  if( strcmp( line, "REGISTER\n" ) == 0 )
    {
      state = REGISTER;
      return;
    }
  else if( strcmp( line, "MEMORY\n" ) == 0 )
    {
      state = MEMORY;
      return;
    }
  else if( strcmp( line, "CODE\n" ) == 0 )
    {
      state = CODE;
      return;
    }
  else if( strcmp( line, "\n" ) == 0 )
    return;
  else
    {
      if( state == REGISTER )
	{
	  read_register_section( line );
	}
      else if( state == MEMORY )
	{
	  read_memory_section( line );
	}
      else if( state == CODE )
	{
	  read_code_section( line );
	}
      else
	{
	  /* houston, we have a problem */
#ifdef __DEBUG__
	  printf( "Malformed code!: %s\n", line );
#endif
	  return;
	}
    }
}

struct instmem *
create_ld( char * cmd )
{
  /* TODO */
  
}

struct instmem *
create_sd( char * cmd )
{
  /* TODO */
  return NULL;
}

struct instmem *
create_dadd( char * cmd )
{
  /* TODO */
  return NULL;
}

struct instmem *
create_sub( char * cmd )
{
  /* TODO */
  return NULL;
}

struct instmem *
create_bnez( char * cmd )
{
  /* TODO */
  return NULL;
}

void
push_inst( char * inst )
{
  int _id;
  size_t inst_sz;
  struct instmem * node;

  if( INSTS == NULL )
    {
    }
}
