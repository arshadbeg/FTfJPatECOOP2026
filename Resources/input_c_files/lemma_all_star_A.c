assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  /*@
    loop invariant 0 <= i <= x <= j <= strlen(s);
    loop invariant star_A(s, x, j);
    loop invariant \forall integer m; 0<=i<=m<j ==> s[m]=='A';
    loop assigns x;
    loop variant x;
  */
  while (i < x) {
    x--;
  }
}