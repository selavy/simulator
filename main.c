#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define __DEBUG__

#include "Pipeline.h"
#include "Register.h"
#include "SimIO.h"
#include "Memory.h"

char * infile = NULL;
char * outfile = NULL;

char * dftoutfile = "output.out";
char * dftinfile = "input.txt";

int main( int argc, char ** argv )
{
  if( argc < 2 )
    {
      infile = dftinfile;
      outfile = dftoutfile;
    }
  else if( argc == 3 )
    {
      infile = argv[1];
      outfile = dftoutfile;
    }
  else
    {
      infile = argv[1];
      outfile = argv[2];
    }

  init_regs();
  init_memfile();
  read_input( infile );

  print_code_listing();

  do
    {
      WB();
      MEM3();
      MEM2();
      MEM1();
      EX();
      ID();
      IF2();
      IF1();
    } while( /* another command */ 0 );

  close_input();
  return 0;
}
