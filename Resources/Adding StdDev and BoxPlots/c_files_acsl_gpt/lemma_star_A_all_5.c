/*@
  requires s != \null;
  requires i <= j;
  assigns \nothing;
  loop invariant i <= x <= j;
  loop assigns x;
  loop variant j - x;
  ensures x == j;  // after the loop terminates
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

