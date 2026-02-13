/*
  @ requires c is defined;
  @ ensures \result == d(e(d(c)));
*/
int ded(char c) {
  return d(e(d(c)));
}
