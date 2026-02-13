/*@
  requires x63 >= 0;
  requires x66 >= 0;
  requires \valid_read(x62 + (0 .. x63-1));
  requires \valid_read(x65 + (0 .. x66-1));
  requires \valid_read(x61 + (0 .. x63-1));
  requires \valid_read(x64 + (0 .. x66-1));
  requires \forall integer i;
            0 <= i < x63 ==>
              \valid_read(x61[i] + (0 .. x62[i]-1)) &&
              \valid_read(x64[i] + (0 .. x65[i]-1));
  assigns \nothing;
  ensures \result == 1 <==>
          (x63 == x66 &&
           \forall integer i;
             0 <= i < x63 ==>
               eq_vec_Int(x61[i], x62[i], x64[i], x65[i]) == 1);
*/
int eq_vec_vec_Int(int **x61, int *x62, int x63,
                   int **x64, int *x65, int x66) {
  int x68 = x63 == x66;
  int x84;

  if (x68) {
    int x83 = 1;
    for (int x71 = 0; x71 < x63; x71++) {
      if (!eq_vec_Int(x61[x71], x62[x71],
                      x64[x71], x65[x71])) {
        x83 = 0; break;
      }
    }
    x84 = x83;
  } else {
    x84 = 0;
  }
  return x84;
}

