assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  /*@
	requires x>0;
	loop invariant 0<=i<=x-1;
	loop assigns i, ;
	loop variant x-1-i;
*/
while (i < x) {
    x--;
  }
}