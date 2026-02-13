// ACSL annotation for matcher_a_or_b.c
/*
@requires x0 != NULL;
@ensures \result == 1 
    <=> (x0 != NULL 
         && ((x0[0] == 'a' && (strlen(x0) == 1)) 
             || (x0[0] == 'b' && (strlen(x0) == 1))));
@ensures \result == 0 otherwise;
*/

// @function matcher_a_or_b
// @ensures \result == 1 <=> (x0[0] == 'a' && x0[1] == '\0' || x0[0] == 'b' && x0[1] == '\0');
int matcher_a_or_b(char * x0) {
  /*@ assume x0 != NULL; */
  char x2 = x0[0];
  int x3 = x2 == '\0'; // true if x0 is empty

  int x9;
  if (x3) {
    x9 = 0; // empty string, false
  } else {
    int x4 = x2 == 'a';
    int x8;
    if (x4) {
      char *x5 = x0 + 1;
      /*@ assume x5 != NULL; */ // since x0[0] != '\0'
      char x6 = x5[0];
      int x7 = x6 == '\0';
      x8 = x7; // true if x0 is exactly "a"
    } else {
      x8 = 0;
    }
    x9 = x8;
  }

  int x12;
  if (x3) {
    x12 = 0;
  } else {
    int x10 = x2 == 'b';
    int x11;
    if (x10) {
      char *x5 = x0 + 1;
      /*@ assume x5 != NULL; */
      char x6 = x5[0];
      int x7 = x6 == '\0';
      x11 = x7; // true if x0 is exactly "b"
    } else {
      x11 = 0;
    }
    x12 = x11;
  }

  int x13 = x9 || x12; // true if x0 is exactly "a" or exactly "b"
  return x13;
}
