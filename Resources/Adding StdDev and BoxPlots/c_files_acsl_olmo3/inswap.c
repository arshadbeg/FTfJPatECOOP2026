/*
  @ file inswap.c
  @brief Array swap and (potentially buggy) selection sort functions
*/

/*
  @ requires x0 != NULL;
  @ requires x1 >= 0;
  @ requires x2 >= 0;
  @ requires x1 < \length(x0);
  @ requires x2 < \length(x0);
  @ ensures x0[x1] == \old(x0[x2]) && x0[x2] == \old(x0[x1]);
*/
void inswap(int *x0, int x1, int x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}

/*
  @ requires x25 != NULL;
  @ requires x26 >= 0;
  @ requires \valid(x25 + 0 .. x25 + x26 - 1);
  @ ensures 
      // The code as written does not guarantee sorting.
      // It appears to attempt selection sort but only updates x33 when x37 >= x39,
      // which is incorrect for finding the minimum.
      // As a result, the postcondition cannot guarantee sorting.
      // For documentation, we keep a weak postcondition:
      \true;
*/
void insort(int *x25, int x26) {
  int x29 = x26;
  for (;;) {
    int x30 = x29;
    int x31 = x30 > 1;
    if (!x31) break;
    int x33 = 0;
    int x34 = x29;
    for (int x36 = 0; x36 < x34; x36++) {
      int x37 = x25[x36];
      int x38 = x33;
      int x39 = x25[x38];
      int x40 = x37 >= x39;
      if (x40) {
        // Only updates x33 if x37 >= x39, which is NOT the minimum selection.
        x33 = x36;
      }
      // else: x33 is not updated, so it may not track the minimum.
    }
    int x96 = x33;
    int x95 = x34 - 1;
    inswap(x25, x95, x96);

    x29 = x95;
  }
}
