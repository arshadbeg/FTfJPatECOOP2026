void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  /*@
    loop invariant 0<=i<=x<=m<j;
    loop invariant !star_A(s, x, j);
    loop assigns x;
    loop variant x;
  */
  while (i < x) {
    x--;
  }
}