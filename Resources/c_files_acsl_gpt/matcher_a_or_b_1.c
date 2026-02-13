/*@ 
  requires s != \null;
  assigns \nothing;
  ensures \result == 1 <==> 
          ((s[0] == 'a' || s[0] == 'b') && s[1] == '\0');
*/
int matcher_a_or_b(char  * s) {
  char x2 = s[0];
  int x3 = x2 == '\0';
  int x9;
  if (x3) {
    x9 = 0;
  } else {
    int x4 = x2 == 'a';
    int x8;
    if (x4) {
      char  *x5 = s+1;
      char x6 = x5[0];
      int x7 = x6 == '\0';
      x8 = x7;
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
      char  *x5 = s+1;
      char x6 = x5[0];
      int x7 = x6 == '\0';
      x11 = x7;
    } else {
      x11 = 0;
    }
    x12 = x11;
  }
  int x13 = x9 || x12;
  return x13;
}

