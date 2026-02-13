
/*@
  ensures (s[k] == c) ==> \result==k;
*/
static int indexOf(char* s, char c, int from, int to) {
  
  /*@
	loop invariant 0<=i<=None-1;
	loop assigns i, ;
*/
for(int k = from; k < to; k++) {
    if(s[k] == c) {
      return k;
    }
  }
  return -1;
}