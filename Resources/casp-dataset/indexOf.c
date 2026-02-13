/*@  requires 0 <= from <= to;
  @  requires \valid(s+(0..to-1));
  @  ensures -1 == \result || from <= \result < to;
  @  ensures \result == -1 ==>
  @     (\forall int i; from <= i < to ==> s[i] != c);
  @  ensures from <= \result < to ==>
  @     s[\result] == c &&
  @     (\forall int i; from <= i < \result ==> s[i] != c);
  @  assigns \nothing;
  @*/
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