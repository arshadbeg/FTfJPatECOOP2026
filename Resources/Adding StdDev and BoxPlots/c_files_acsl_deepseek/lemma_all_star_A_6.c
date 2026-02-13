/*@ requires \valid(s);
    requires i <= j;
    assigns \nothing;
    ensures x <= i;
    ensures \at(x, Pre) == j;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  /*@ loop invariant i <= x <= \at(x, LoopEntry);
      loop invariant \at(x, LoopEntry) == j;
      loop assigns x;
      loop variant x - i;
  */
  while (i < x) {
    x--;
  }
}
