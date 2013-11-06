#ifndef __SIM_IO_H__
#define __SIM_IO_H__

#ifndef __DEBUG__
#define __DEBUG__
#endif

#include<stdio.h>
#include<string.h>

#include "Memory.h"
#include "Register.h"

#define MAX_STR_LEN 512

enum READ_STATE {
  REGISTER,
  MEMORY,
  CODE,
  START,
  END,
  UNDEF
};

struct instmem
{
  unsigned int _id;
  char * inst;
  size_t inst_sz;
  struct instmem * next;
  struct instmem * prev;
};

struct jmptbl
{
  char * jmplbl;
  struct instmem * _inst;
  struct jmptbl * next;
};

static FILE * pFile = NULL;
static int file_read = 0;
static enum READ_STATE state = START;
static struct instmem * INSTS = NULL;
static struct jmptbl * JMPTBL = NULL;
static struct instmem * curr = NULL;

int
read_register_section( char * line );

int
read_memory_section( char * line );

struct instmem *
read_code_section( char * line );

/* open and read the input file */
/* returns 0 on success */
int
read_input( char * );

void
close_input();

void
read();

struct instmem *
create_ld( char * );

struct instmem *
create_sd( char * );

struct instmem *
create_dadd( char * );

struct instmem *
create_sub( char * );

struct instmem *
create_bnez( char * );

#endif
