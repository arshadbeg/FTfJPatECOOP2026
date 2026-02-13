/*
  @ file index.c
  @brief Functions for indexing and array operations
*/

/*
  @ requires x2 >= 0;
  @ requires x1 >= 0;
  @ requires x3 is an integer;
  @ ensures \result == (x2 * x1) + x3;
*/
int index(int x0, int x1, int x2, int x3) {
  int x5 = x2 * x1;
  int x6 = x5 + x3;
  return x6;
}

/*
  @ requires x63 != NULL;
  @ requires x66 != NULL;
  @ requires x69 != NULL;
  @ requires x70 >= 0;
  @ requires x71 >= 0;
  @ requires \valid(x63 + 0 .. x69 + x70 * x71 - 1);
  @ requires \valid(x66 + 0 .. x66 + x70 * x71 - 1);
  @ requires \valid(x69 + 0 .. x69 + x70 * x71 - 1);
  @ ensures 
      \forall integer i; 0 <= i < x70;
      \forall integer j; 0 <= j < x71;
        let idx1 = index(x64, x65, i, j);
        let idx2 = index(x67, x68, i, j);
        let idx3 = index(x70, x71, i, j);
        x69[idx3] == ((x63[idx1] != 0) || (x66[idx2] != 0));
      // or, more compactly:
      \forall integer i; 0 <= i < x70;
      \forall integer j; 0 <= j < x71;
        x69[index(x70, x71, i, j)] = (x63[index(x64, x65, i, j)] != 0) || (x66[index(x67, x68, i, j)] != 0);
*/
void add(int *x63, int x64, int x65, int *x66, int x67, int x68, int *x69, int x70, int x71) {
  for (int x76 = 0; x76 < x70; x76++) {
    for (int x78 = 0; x78 < x71; x78++) {
      int x79 = index(x64, x65, x76, x78);
      int x80 = x63[x79];
      int x81 = index(x67, x68, x76, x78);
      int x82 = x66[x81];
      int x83 = x80 != 0 || x82 != 0;
      int x84 = index(x70, x71, x76, x78);
      x69[x84] = x83;
    }
  }
}

/*
  @ requires x111 != NULL;
  @ requires x114 != NULL;
  @ requires x112 is an integer array index base;
  @ requires x115 >= 0;
  @ requires x116 >= 0;
  @ requires \valid(x111 + 0 .. x111 + x115 * x116 - 1);
  @ requires \valid(x114 + 0 .. x114 + x115 * x116 - 1);
  @ requires x110 is a flag for scalar multiplication;
  @ ensures 
      \forall integer i; 0 <= i < x115;
      \forall integer j; 0 <= j < x116;
        if (x110 != 0) then
          x114[index(x115, x116, i, j)] == x111[index(x112, x113, i, j)];
        else
          x114[index(x115, x116, i, j)] == 0;
*/
void scalar_mult(int x110, int *x111, int x112, int x113, int *x114, int x115, int x116) {
  for (int x121 = 0; x121 < x115; x121++) {
    for (int x123 = 0; x123 < x116; x123++) {
      int idx_src = index(x112, x113, x121, x123);
      int idx_dst = index(x115, x116, x121, x123);
      int x126;
      if (x110 != 0) {
        x126 = x111[idx_src];
      } else {
        x126 = 0;
      }
      x114[idx_dst] = x126;
    }
  }
}
