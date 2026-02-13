/*@
  requires s != \null;
  requires 0 <= from <= to;
  requires \valid_read(s + (from .. to-1));
  assigns \nothing;
  ensures from <= \result < to ==> s[\result] == c;
  ensures \result == -1 ==> (\forall integer k; from <= k < to ==> s[k] != c);
*/
static int indexOf(char* s, char c, int from, int to) {
  for(int k = from; k < to; k++) {
    if(s[k] == c) return k;
  }
  return -1;
}

