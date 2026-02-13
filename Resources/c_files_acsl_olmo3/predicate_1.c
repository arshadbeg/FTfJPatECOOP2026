// ACSL annotation for predicate.c
/*
@requires true;
@ensures \result == 1 <=> (v % 2 == 0);
@ensures \result == 0 <=> (v % 2 != 0);
*/

// @function predicate
// @ensures \result is 1 if v is even, 0 if v is odd;
int predicate(int v) {
  return v % 2 == 0;
}
