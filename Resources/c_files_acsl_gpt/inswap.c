#include <limits.h>

/*@
  requires \valid(x0 + (0 .. x1)) && \valid(x0 + (0 .. x2));
  assigns x0[x1], x0[x2];
  ensures x0[x1] == \old(x0[x2]);
  ensures x0[x2] == \old(x0[x1]);
  ensures (\forall integer k; k != x1 && k != x2 ==> x0[k] == \old(x0[k]));
*/
void inswap(int *x0, int x1, int x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}

/*@
  requires \valid(x25 + (0 .. x26-1));
  assigns x25[0 .. x26-1];
  ensures (\forall integer i,j; 0 <= i < j < x26 ==> x25[i] <= x25[j]);
*/
void insort(int *x25, int x26) {
  int x29 = x26;
  for (;;) {
    int x30 = x29;
    int x31 = x30 > 1;
    if (!x31) break;
    int x33 = 0;
    int x34 = x29;
    
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

