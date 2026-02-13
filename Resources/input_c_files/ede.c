/*@
assigns \nothing;
ensures e(d(e(i)))==e(i);
*/
char ede(int i) {
  return e(d(e(i)));
}