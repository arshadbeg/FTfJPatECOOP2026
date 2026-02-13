#include <limits.h>



/*@
  ensures (x21) ==> \result==x33;
  ensures !(x21) ==> \result==x33;
*/
int eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) {
  int x21 = x17 == x19;
  int x33;
  if (x21) {
    int x32 = 1;
    
    /*@
	loop invariant 0<=i<=None-1;
	loop assigns i, ;
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



/*@
  ensures (x68) ==> \result==x84;
  ensures !(x68) ==> \result==x84;
*/
int eq_vec_vec_Int(int  * * x61, int  * x62, int  x63, int  * * x64, int  * x65, int  x66) {
  int x68 = x63 == x66;
  int x84;
  if (x68) {
    int x83 = 1;
    
    /*@
	loop invariant 0<=i<=None-1;
	loop assigns i, ;
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