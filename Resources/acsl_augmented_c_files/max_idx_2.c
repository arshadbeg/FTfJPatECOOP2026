/*@
  ensures (t[max] < t[i]) ==> \result==max;
*/
int max_idx(unsigned int *t, int len) {
  int max = 0;
  
  /*@
	requires len>0;
	loop invariant 0<=i<=len-1;
	loop assigns i, ;
	loop variant len-1-i;
*/
for(int i = 1; i < len; i++)
    if (t[max] < t[i])
      max = i;
  return max;
}