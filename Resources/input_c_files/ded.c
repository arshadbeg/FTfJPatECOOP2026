/*@
assigns \nothing;
ensures d(e(d(c)))==d(c);
*/
int ded(char c) {
  return d(e(d(c)));
}