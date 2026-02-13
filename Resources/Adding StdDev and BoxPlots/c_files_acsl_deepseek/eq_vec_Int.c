#include <limits.h>

/*@ requires x17 >= 0 && x19 >= 0;
    requires \valid(x16 + (0..x17-1)) && \valid(x18 + (0..x19-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> (x17 == x19 && (\forall integer i; 0 <= i < x17 ==> x16[i] == x18[i]));
*/
int eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) {
  int x21 = x17 == x19;
  int x33;
  if (x21) {
    int x32 = 1;
    
    /*@ loop invariant 0 <= x24 <= x17;
        loop invariant x32 == 1 <==> (\forall integer i; 0 <= i < x24 ==> x16[i] == x18[i]);
        loop assigns x24, x32;
        loop variant x17 - x24;
    */
    for (int x24 = 0; x24 < x17; x24++) {
      int x29 = x16[x24];
      int x30 = x18[x24];
      int x31 = x29 == x30;
      if (!x31) { x32 = 0; break; }
    }
    x33 = x32;
  } else {
    x33 = 0/*false*/;
  }
  return x33;
}

/*@ requires x63 >= 0 && x66 >= 0;
    requires \valid(x61 + (0..x63-1)) && \valid(x64 + (0..x66-1));
    requires \valid(x62 + (0..x63-1)) && \valid(x65 + (0..x66-1));
    requires \forall integer i; 0 <= i < x63 ==> \valid(x61[i] + (0..x62[i]-1));
    requires \forall integer i; 0 <= i < x66 ==> \valid(x64[i] + (0..x65[i]-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> (x63 == x66 && (\forall integer i; 0 <= i < x63 ==> 
            x62[i] == x65[i] && (\forall integer j; 0 <= j < x62[i] ==> x61[i][j] == x64[i][j])));
*/
int eq_vec_vec_Int(int  * * x61, int  * x62, int  x63, int  * * x64, int  * x65, int  x66) {
  int x68 = x63 == x66;
  int x84;
  if (x68) {
    int x83 = 1;
    
    /*@ loop invariant 0 <= x71 <= x63;
        loop invariant x83 == 1 <==> (\forall integer i; 0 <= i < x71 ==> 
                eq_vec_Int(x61[i], x62[i], x64[i], x65[i]) == 1);
        loop assigns x71, x83;
        loop variant x63 - x71;
    */
    for (int x71 = 0; x71 < x63; x71++) {
      int  *x78 = x61[x71];
      int x79 = x62[x71];
      int  *x80 = x64[x71];
      int x81 = x65[x71];
      int x82 = eq_vec_Int(x78,x79,x80,x81);
      if (!x82) { x83 = 0; break; }
    }
    x84 = x83;
  } else {
    x84 = 0/*false*/;
  }
  return x84;
}
