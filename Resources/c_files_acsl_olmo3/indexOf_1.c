/*
  @ requires s != NULL;
  @ requires from >= 0;
  @ requires to >= from;
  @ ensures 
      (\exists integer k; from <= k < to && s[k] == c) 
        ==> \result == k0 where k0 is the smallest such k
      && 
      (\forall integer k; from <= k < to && s[k] != c) 
        ==> \result == -1;
*/
static int indexOf(char* s, char c, int from, int to) {
  for (int k = from; k < to; k++) {
    if (s[k] == c) {
      return k;
    }
  }
  return -1;
}
