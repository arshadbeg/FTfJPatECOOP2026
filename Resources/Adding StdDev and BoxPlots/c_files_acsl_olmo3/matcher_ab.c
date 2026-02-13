// ACSL annotation for matcher_ab.c
/*
@requires x0 != NULL;
@ensures \result == 1 <=> (x0[0] == 'a' && x0[1] == 'b' && x0[2] == '\0');
@ensures \result == 0 otherwise;
*/

// @function matcher_ab
// @ensures \result == 1 <=> (x0 == "ab");
int matcher_ab(char * x0) {
  //@ assume x0 != NULL;
  char x2 = x0[0];
  int x3 = x2 == '\0';

  int x7;
  if (x3) {
    x7 = 0; //@ ensures x7 == 0;
  } else {
    int x4 = x2 == 'a';
    int x6;
    if (x4) {
      x6 = 0;
    } else {
      x6 = 0;
    }
    x7 = x6; //@ ensures x7 == 0;
  }

  int x17;
  if (x3) {
    x17 = 0; //@ ensures x17 == 0;
  } else {
    int x4b = x2 == 'a';
    int x16;
    if (x4b) {
      char *x5 = x0 + 1; //@ assume x5 != NULL;
      char x8 = x5[0];
      int x9 = x8 == '\0';
      int x15;
      if (x9) {
        x15 = 0; //@ ensures x15 == 0;
      } else {
        int x10 = x8 == 'b';
        int x14;
        if (x10) {
          char *x11 = x5 + 1; //@ assume x11 != NULL;
          char x12 = x11[0];
          int x13 = x12 == '\0';
          x14 = x13;
        } else {
          x14 = 0;
        }
        x15 = x14;
      }
      x16 = x15;
    } else {
      x16 = 0;
    }
    x17 = x16;
  }

  int x18 = x7 || x17;
  return x18;
}
