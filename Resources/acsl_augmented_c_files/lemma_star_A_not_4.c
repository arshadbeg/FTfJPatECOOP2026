void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
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