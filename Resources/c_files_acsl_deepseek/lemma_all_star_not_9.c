/*@ requires \valid(s);
    requires i <= m;
    assigns \nothing;
    ensures x <= i;
    ensures \at(x, Pre) == m;
*/
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  /*@ loop invariant i <= x <= \at(x, LoopEntry);
      loop invariant \at(x, LoopEntry) == m;
      loop assigns x;
      loop variant x - i;
  */
  while (i < x) {
    x--;
  }
}
