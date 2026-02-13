/*
  @ requires x1 >= 0; // If negative, multiplication may be undefined for overflow
  @ requires x2 is an integer;
  @ requires x3 is an integer;
  @ ensures \result == (x2 * x1) + x3;
*/
int index(int x0, int x1, int x2, int x3) {
  int x5 = x2 * x1;
  int x6 = x5 + x3;
  return x6;
}
