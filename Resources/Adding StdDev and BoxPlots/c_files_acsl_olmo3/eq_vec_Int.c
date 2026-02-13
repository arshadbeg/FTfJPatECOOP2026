/*
  @ requires x16 != NULL;
  @ requires x18 != NULL;
  @ requires x17 >= 0;
  @ requires x19 >= 0;
  @ ensures 
      \result == 1 
      <==> 
      (x17 == x19 && \forall integer i; 0 <= i < x17 ==> x16[i] == x18[i])
      && 
      \result == 0 
      <==> 
      (x17 != x19 || \exists integer i; 0 <= i < x17 && x16[i] != x18[i]);
*/
int eq_vec_Int(int *x16, int x17, int *x18, int x19) {
  int x21 = x17 == x19;
  int x33;
  if (x21) {
    int x32 = 1;
    for (int x24 = 0; x24 < x17; x24++) {
      if (x16[x24] != x18[x24]) {
        x32 = 0;
        break;
      }
    }
    x33 = x32;
  } else {
    x33 = 0;
  }
  return x33;
}
