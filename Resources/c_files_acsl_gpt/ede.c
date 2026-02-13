/*@
  ensures \result == e(d(e(i)));
*/
char ede(int i) {
  return e(d(e(i)));
}

