/*
  @ requires x61 != NULL;
  @ requires x62 != NULL;
  @ requires x64 != NULL;
  @ requires x65 != NULL;
  @ requires x63 >= 0;
  @ requires x66 >= 0;
  @ ensures 
      \result == 1 
      <==> 
      (x63 == x66 && 
       \forall integer i; 0 <= i < x63 ==> eq_vec_Int(x61[i], x62[i], x64[i], x65[i]) == 1)
      && 
      \result == 0 
      <==> 
      (x63 != x66 || \exists integer i; 0 <= i < x63 && eq_vec_Int(x61[i], x62[i], x64[i], x65[i]) != 1);
*/
int eq_vec_vec_Int(int **x61, int *x62, int x63, int **x64, int *x65, int x66) {
  int x68 = x63 == x66;
  int x84;
  if (x68) {
    int x83 = 1;
    for (int x71 = 0; x71 < x63; x71++) {
      // eq_vec_Int expects: (ptr to int array, length, ptr to int array, length)
      int x82 = eq_vec_Int(x61[x71], x62[x71], x64[x71], x65[x71]);
      if (!x82) {
        x83 = 0;
        break;
      }
    }
    x84 = x83;
  } else {
    x84 = 0;
  }
  return x84;
}
