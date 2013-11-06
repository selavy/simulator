#ifndef __REGISTER_H__
#define __REGISTER_H__

#ifndef __DEBUG__
#define __DEBUG__
#endif

#include<stdint.h>

#define REGFILESIZE 32

typedef int32_t Register;
typedef Register RegisterFile[REGFILESIZE];

static RegisterFile theRegisterFile;

/* set all registers to 0 */
void
init_regs();

/* set given register (by str) to 0 */
int
set_reg( char *, Register );

/* set given register (by int) to 0 */
int
set_regi( int, Register );

/* return the current value of the register (by str) */
/* returns 0 if register not found */
Register
get_reg( char * );

/* return the current value of the register (by int) */
/* returns 0 if register not found */
Register
get_regi( int );

/* print the all non 0 values in register file */
void
print_regs();

#endif
