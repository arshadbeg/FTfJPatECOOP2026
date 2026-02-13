/*
  @ requires i is defined;
  @ requires \valid(e(i));
  @ ensures \result == d(e(i));
  // If e(i) is not a char, adjust accordingly.
*/
int de(int i) {
  return d(e(i));
}
