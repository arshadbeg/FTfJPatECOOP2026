/*@ 
  requires s != \null;
  assigns \nothing;
  ensures \result == 1 <==> (s[0] == 'a' && s[0] != '\0');
*/
int matcher(char  * s) {
  int x2 = strlen(s);
  int x3 = 0 < x2;
  int x6;
  if (x3) {
    char x4 = s[0];
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

