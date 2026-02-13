#include <limits.h>

/*@ requires \valid(x0 + (0..\max(x1, x2)));
    requires x1 >= 0 && x2 >= 0;
    assigns x0[x1], x0[x2];
    ensures x0[x1] == \old(x0[x2]);
    ensures x0[x2] == \old(x0[x1]);
    ensures \forall integer i; i != x1 && i != x2 ==> x0[i] == \old(x0[i]);
*/
void inswap(int  * x0, int  x1, int  x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}

/*@ requires x26 >= 0;
    requires \valid(x25 + (0..x26-1));
    assigns x25[0..x26-1];
    ensures \forall integer i; 0 <= i < x26-1 ==> x25[i] >= x25[i+1]; // descending order
    ensures \forall integer i,j; 0 <= i < j < x26 ==> x25[i] >= x25[j]; // fully sorted descending
*/
void insort(int  * x25, int  x26) {
  int x29 = x26;
  
  /*@ loop invariant 1 <= x29 <= x26;
      loop invariant \forall integer i; x29 <= i < x26 ==> 
              \forall integer j; i < j < x26 ==> x25[i] >= x25[j]; // suffix is sorted
      loop invariant \forall integer i; x29 <= i < x26 ==> 
              x25[i] == \at(x25[i], Pre); // unchanged beyond current position
      loop assigns x29, x25[0..x29-1];
      loop variant x29;
  */
  for (;;) {
    int x30 = x29;
    int x31 = x30 > 1;
    if (!x31) break;
    int x33 = 0;
    int x34 = x29;
    
    /*@ loop invariant 0 <= x36 <= x34;
        loop invariant 0 <= x33 < x36 || x36 == 0;
        loop invariant \forall integer k; 0 <= k < x36 ==> x25[x33] >= x25[k];
        loop assigns x36, x33;
        loop variant x34 - x36;
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
