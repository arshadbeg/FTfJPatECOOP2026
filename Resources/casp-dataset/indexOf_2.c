static int indexOf(char* s, char c, int from, int to) {
  /*@ loop invariant from <= k <= to;
    @ loop invariant \forall int i; from <= i < k ==> s[i] != c;
    @ loop assigns k;
    @ loop variant to - k;
    @*/
  for(int k = from; k < to; k++) {
    if(s[k] == c) {
      return k;
    }
  }
  return -1;
}