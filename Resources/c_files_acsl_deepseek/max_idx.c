/*@ requires len > 0;
    requires \valid(t + (0..len-1));
    assigns \nothing;
    ensures 0 <= \result < len;
    ensures \forall integer i; 0 <= i < len ==> t[i] <= t[\result];
*/
int max_idx(unsigned int *t, int len) {
  int max = 0;
  
  /*@ loop invariant 1 <= i <= len;
      loop invariant 0 <= max < i;
      loop invariant \forall integer j; 0 <= j < i ==> t[j] <= t[max];
      loop assigns i, max;
      loop variant len - i;
  */
  for(int i = 1; i < len; i++)
    if (t[max] < t[i])
      max = i;
  return max;
}
