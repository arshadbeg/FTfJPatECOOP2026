assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  /*@
    loop invariant 0 <= i <= x <= j <= strlen(s);
    loop invariant star_A(s, x, j);
    loop invariant \forall integer m; i<=m<x ==> s[m]=='A';
    loop assigns x;
    loop variant j-x;
  */
  while (x < j) {
    x++;
  }
}