/*@
  ensures \result == d(e(i));
*/
int de(int i) {
  return d(e(i));
}

