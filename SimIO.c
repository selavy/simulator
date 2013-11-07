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
  char rs[MAX_STR_LEN];
  char rt[MAX_STR_LEN];
  char rd[MAX_STR_LEN];
  int offset;

#ifdef __DEBUG__
  printf("read_code_section(): %s", line );
#endif

  /* TODO */
  /* get rs, rt, rd, and offset for each command */
  /* update instmem to hold rs, rt, rt, offset */

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
  push_inst( cmd );
  return NULL;  
}

struct instmem *
create_sd( char * cmd )
{
  /* TODO */
  push_inst( cmd );
  return NULL;
}

struct instmem *
create_dadd( char * cmd )
{
  /* TODO */
  push_inst( cmd );
  return NULL;
}

struct instmem *
create_sub( char * cmd )
{
  /* TODO */
  push_inst( cmd );
  return NULL;
}

struct instmem *
create_bnez( char * cmd )
{
  /* TODO */
  push_inst( cmd );
  return NULL;
}

void
push_inst( char * inst )
{
  int _id;
  size_t inst_sz;
  struct instmem * node;
  struct instmem * prev;

  if( INSTS == NULL )
    {
      INSTS = malloc( sizeof *INSTS );
      if( INSTS == NULL )
	return;

      node = INSTS;
      curr = INSTS;
      prev = NULL;
    }
  else
    {
      if( curr == NULL )
	curr = INSTS; /* INSTS can't be NULL */

      (*curr).next = malloc( sizeof( *(*curr).next ) );
      if( (*curr).next == NULL )
	return;

      node = (*curr).next;
      prev = curr;
      curr = node;
    }

      inst_sz = strlen( inst ) + 1;
      (*node).inst = malloc( sizeof( char ) * inst_sz );

      if( (*node).inst == NULL )
	{
	  free( INSTS );
	  INSTS = NULL;
	  return;
	}

      strncpy( (*node).inst, inst, inst_sz );
      (*node).inst_sz = inst_sz;
      (*node).prev = prev;
      (*node).next = NULL;
}

void
print_code_listing()
{
#ifdef __DEBUG__
  struct instmem * n;

  n = INSTS;

  while( n != NULL )
    {
      printf("%s\n", (*n).inst );
      n = (*n).next;
    }
#endif
}
