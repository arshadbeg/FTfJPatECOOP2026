#include <limits.h>

void inswap(int  * x0, int  x1, int  x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}

void insort(int  * x25, int  x26) {
  int x29 = x26;
  
  /*@
	loop invariant 0<=i<=None-1;
	loop assigns i, ;
*/
for (;;) {
    int x30 = x29;
    int x31 = x30 > 1;
    if (!x31) break;
    int x33 = 0;
    int x34 = x29;
    
    /*@
	loop invariant 0<=i<=None-1;
	loop assigns i, ;
*/
for(int x36=0; x36 < x34; x36++) {
      int x37 = x25[x36];
      int x38 = x33;
      int x39 = x25[x38];
      int x40 = x37 >= x39;
      if (x40) {
        x33 = x36;
      } else {
      }
    }
    int x96 = x33;
    int x95 = x34 - 1;
    inswap(x25,x95,x96);
    
    
    
    x29 = x95;
  }
}