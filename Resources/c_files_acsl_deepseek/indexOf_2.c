/*@ requires \valid(s + (from..to-1));
    requires from <= to;
    assigns \nothing;
    ensures -1 <= \result < to;
    ensures \result >= 0 ==> s[\result] == c && \forall integer k; from <= k < \result ==> s[k] != c;
    ensures \result == -1 ==> \forall integer k; from <= k < to ==> s[k] != c;
*/
static int indexOf(char* s, char c, int from, int to) {
  
  /*@ loop invariant from <= k <= to;
      loop invariant \forall integer i; from <= i < k ==> s[i] != c;
      loop assigns k;
      loop variant to - k;
  */
  for(int k = from; k < to; k++) {
    if(s[k] == c) {
      return k;
    }
  }
  return -1;
}
