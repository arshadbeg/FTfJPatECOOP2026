
/*@
  ensures (predicate(v[i]) ==> \result==r;
*/
int index_where(int* v, int n, int* o) {
  int r = 0;
  
  /*@
	requires n>0;
	loop invariant 0<=i<=n-1;
	loop assigns i, ;
	loop variant n-1-i;
*/
for (int i = 0; i < n; i++) {
    if (predicate(v[i])) {
      o[r++] = i;
    }
  }
  return r;
}