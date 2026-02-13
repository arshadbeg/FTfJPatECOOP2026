/*@
  requires s != \null;
  requires 0 <= i <= j <= n;
  assigns \nothing;
  loop invariant i <= x <= j;
  loop assigns x;
  loop variant x - i;
  ensures x == i;  // after the loop terminates
*/
void lemma_star_A(char* s, int i, int j, int n) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

