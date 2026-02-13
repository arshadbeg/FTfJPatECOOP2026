/*
  @ requires i is defined;
  @ requires \valid(e(i));
  @ requires \valid(d(e(i)));
  @ ensures \result == e(d(e(i)));
*/
char ede(int i) {
  return e(d(e(i)));
}
