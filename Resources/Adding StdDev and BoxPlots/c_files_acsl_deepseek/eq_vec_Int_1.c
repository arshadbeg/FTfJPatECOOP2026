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
