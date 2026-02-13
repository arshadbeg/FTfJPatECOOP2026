/*@ requires \valid(t+(0..len-1));
  @ requires len > 0;
  @ assigns \nothing;
  @ ensures len == 0 ==> \result == 0;
  @ ensures \forall integer n; 0 <= n < len ==> t[\result] >= t[n];
  @ ensures 0 <= \result < len;
  @ */
int max_idx(unsigned int *t, int len) {
  int max = 0;
  /*@loop invariant 1 <= i <= len;
    @loop invariant \forall integer n; 0 <= n < i ==> t[max] >= t[n];
    @loop invariant 0 <= max < len;
    @loop assigns i, max;
    @loop variant len - i;
    @ */
  for(int i = 1; i < len; i++)
    if (t[max] < t[i])
      max = i;
  return max;
}