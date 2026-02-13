/*@ requires \valid_function(max_idx);
    requires len >= 0;
    requires \valid(t + (0..len-1)) || len == 0;
    assigns \nothing;
    ensures len <= 0 ==> \result == -1;
    ensures len > 0 ==> \result >= 0 && \result == t[max_idx(t, len)];
    ensures len > 0 ==> \forall integer i; 0 <= i < len ==> t[i] <= \result;
*/
int max_seq(unsigned int *t, int len) {
  if (len <= 0) return -1;
  return t[max_idx(t, len)];
}
