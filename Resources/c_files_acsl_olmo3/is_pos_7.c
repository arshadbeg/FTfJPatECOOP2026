/*
  @ requires x0 is an integer;
  @ ensures \result == (x0 > 0);
*/
int is_pos(int x0) {
  int x2 = x0 > 0;
  return x2;
}

/*
  @ requires x3 is an integer;
  @ ensures \result == (x3 >= 0);
*/
int is_nat(int x3) {
  int x5 = x3 >= 0;
  return x5;
}
