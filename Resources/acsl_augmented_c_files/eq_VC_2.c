/*@
  ensures (n1 != n2) ==> \result==0;
*/
int eq_VC(char *a1, char *a2, int n1, int n2) {
  if (n1 != n2) return 0;
    
    /*@
	requires n1>0;
	loop invariant 0<=i<=n1-1;
	loop assigns i, ;
	loop variant n1-1-i;
*/
for (int i = 0; i < n1; i++) {
      if (a1[i] != a2[i]) return 0;
    }
    return 1;
}