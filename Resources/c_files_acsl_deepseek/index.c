#include <limits.h>

/*@ requires x1 > 0 && x3 >= 0 && x3 < x1;
    requires x2 >= 0;
    assigns \nothing;
    ensures \result == x2 * x1 + x3;
    ensures \result >= 0;
*/
int index(int  x0, int  x1, int  x2, int  x3) {
  int x5 = x2 * x1;
  int x6 = x5 + x3;
  return x6;
}

/*@ requires x64 > 0 && x65 > 0 && x67 > 0 && x68 > 0 && x70 > 0 && x71 > 0;
    requires x70 == x64 && x70 == x67; // all matrices have same rows
    requires x71 == x65 && x71 == x68; // all matrices have same columns
    requires \valid(x63 + (0..x64*x65-1));
    requires \valid(x66 + (0..x67*x68-1));
    requires \valid(x69 + (0..x70*x71-1));
    assigns x69[0..x70*x71-1];
    ensures \forall integer i; 0 <= i < x70 ==> 
            \forall integer j; 0 <= j < x71 ==>
            x69[i*x71 + j] == (x63[i*x65 + j] || x66[i*x68 + j]);
*/
void add(int  * x63, int  x64, int  x65, int  * x66, int  x67, int  x68, int  * x69, int  x70, int  x71) {
  
  /*@ loop invariant 0 <= x76 <= x70;
      loop invariant \forall integer i; 0 <= i < x76 ==> 
              \forall integer j; 0 <= j < x71 ==>
              x69[i*x71 + j] == (x63[i*x65 + j] || x66[i*x68 + j]);
      loop assigns x76, x69[0..x70*x71-1];
      loop variant x70 - x76;
  */
  for(int x76=0; x76 < x70; x76++) {
    
    /*@ loop invariant 0 <= x78 <= x71;
        loop invariant \forall integer j; 0 <= j < x78 ==>
                x69[x76*x71 + j] == (x63[x76*x65 + j] || x66[x76*x68 + j]);
        loop invariant \forall integer i; 0 <= i < x76 ==> 
                \forall integer j; 0 <= j < x71 ==>
                x69[i*x71 + j] == (x63[i*x65 + j] || x66[i*x68 + j]);
        loop assigns x78, x69[x76*x71..x76*x71+x71-1];
        loop variant x71 - x78;
    */
    for(int x78=0; x78 < x71; x78++) {
      int x79 = index(x64,x65,x76,x78);
      int x80 = x63[x79];
      int x81 = index(x67,x68,x76,x78);
      int x82 = x66[x81];
      int x83 = x80 || x82;
      int x84 = index(x70,x71,x76,x78);
      x69[x84] = x83;
    }
  }
}

/*@ requires x112 > 0 && x113 > 0 && x115 > 0 && x116 > 0;
    requires x115 == x112 && x116 == x113; // same dimensions
    requires \valid(x111 + (0..x112*x113-1));
    requires \valid(x114 + (0..x115*x116-1));
    assigns x114[0..x115*x116-1];
    ensures \forall integer i; 0 <= i < x115 ==> 
            \forall integer j; 0 <= j < x116 ==>
            x114[i*x116 + j] == (x110 ? x111[i*x113 + j] : 0);
*/
void scalar_mult(int  x110, int  * x111, int  x112, int  x113, int  * x114, int  x115, int  x116) {
  
  /*@ loop invariant 0 <= x121 <= x115;
      loop invariant \forall integer i; 0 <= i < x121 ==> 
              \forall integer j; 0 <= j < x116 ==>
              x114[i*x116 + j] == (x110 ? x111[i*x113 + j] : 0);
      loop assigns x121, x114[0..x115*x116-1];
      loop variant x115 - x121;
  */
  for(int x121=0; x121 < x115; x121++) {
    
    /*@ loop invariant 0 <= x123 <= x116;
        loop invariant \forall integer j; 0 <= j < x123 ==>
                x114[x121*x116 + j] == (x110 ? x111[x121*x113 + j] : 0);
        loop invariant \forall integer i; 0 <= i < x121 ==> 
                \forall integer j; 0 <= j < x116 ==>
                x114[i*x116 + j] == (x110 ? x111[i*x113 + j] : 0);
        loop assigns x123, x114[x121*x116..x121*x116+x116-1];
        loop variant x116 - x123;
    */
    for(int x123=0; x123 < x116; x123++) {
      int x126;
      if (x110) {
        int x124 = index(x112,x113,x121,x123);
        int x125 = x111[x124];
        x126 = x125;
      } else {
        x126 = 0/*false*/;
      }
      int x127 = index(x115,x116,x121,x123);
      x114[x127] = x126;
    }
  }
}
