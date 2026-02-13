assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  /*@
	loop invariant 0<=i<=None-1;
	loop assigns i, ;
*/
while (x < j) {
    x++;
  }
}