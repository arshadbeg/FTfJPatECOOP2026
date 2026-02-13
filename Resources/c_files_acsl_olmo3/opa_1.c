// ACSL annotation for minus1.c
/*
@requires true;
@ensures \result == x6 - 1;
*/

// @function minus1
// @ensures \result == x6 - 1;
int minus1(int x6) {
  int x8 = x6 - 1;
  return x8;
}
