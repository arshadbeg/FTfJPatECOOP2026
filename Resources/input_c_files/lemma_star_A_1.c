assigns \nothing;
*/
void lemma_star_A(char* s, int i, int j, int n) {
  int x = j;
  /*@
    loop invariant 0 <= i <= x <= j <= n <= strlen(s);
    loop invariant star_A(s, x, n);
    loop invariant star_A(s, i, x);
    loop assigns x;
    loop variant x;
  */
  while (i < x) {
    //@ghost lemma_star_A_dec(s, i, x);
    //@assert i<x;
    //@ghost lemma_star_A_all(s, i, x);
    //@assert s[x-1]=='A';
    //@assert star_A(s, x, n);
    //@assert star_A(s, x-1, n);
    x--;
  }
}