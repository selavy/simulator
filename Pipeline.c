#include "Pipeline.h"

#ifdef __DEBUG__
#include<stdio.h>
#endif

void
IF1() {
#ifdef __DEBUG__
  printf("IF1()\n");
#endif
}

void IF2() {
#ifdef __DEBUG__
  printf("IF2()\n");
#endif
}

void ID() {
#ifdef __DEBUG__
  printf("ID()\n");
#endif
}

void EX() {
#ifdef __DEBUG__
  printf("EX()\n");
#endif
}

void MEM1() {
#ifdef __DEBUG__
  printf("MEM1()\n");
#endif
}

void MEM2() {
#ifdef __DEBUG__
  printf("MEM2()\n");
#endif
}

void MEM3() {
#ifdef __DEBUG__
  printf("MEM3()\n");
#endif
}

void WB() {
#ifdef __DEBUG__
  printf("WB()\n");
#endif
}
