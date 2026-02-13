/*
  @ requires x3 is an integer;
  @ ensures \result == 1 if x3 >= 0 else 0;
  @ ensures \result == (x3 >= 0);
*/
int is_nat(int x3) {
  int x5 = x3 >= 0;
  return x5;
}
