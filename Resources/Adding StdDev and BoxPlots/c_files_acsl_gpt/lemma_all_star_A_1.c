/*@
  requires s != \null;
  requires i <= j;
  assigns \nothing;
  ensures \result == j; // function has no return, so postcondition focuses on logical loop effect
  loop invariant i <= x <= j;
  loop assigns x;
  loop variant x - i;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

