/ ACSL annotation for matcher.c
/*
@requires x0 != NULL;
@ensures \result == 1 <=> (x0[0] == 'a');
@ensures \result == 0 otherwise;
*/

// @function matcher
// @ensures \result == 1 <=> (x0[0] == 'a');
int matcher(char * x0) {
  /*@ assume x0 != NULL; */
  int x2 = strlen(x0);
  int x3 = 0 < x2; // true if x0 is non-empty
  int x6;
  if (x3) {
    char x4 = x0[0];
    int x5 = 'a' == x4;
    x6 = x5;
  } else {
    x6 = 0;
  }
  int x7;
  if (x6) {
    x7 = 1;
  } else {
    x7 = 0;
  }
  return x7;
}
