/*@
  requires s != \null;
  requires i <= m;
  assigns \nothing;
  loop invariant i <= x <= m;
  loop assigns x;
  loop variant x - i;
  ensures x == i;  // after the loop terminates
*/
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  while (i < x) {
    x--;
  }
}

