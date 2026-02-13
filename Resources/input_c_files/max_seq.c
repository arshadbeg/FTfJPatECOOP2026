/*@ requires \valid(t+(0..len-1));
  @ requires len >= 0;
  @ requires \forall integer n; 0 <= n < len ==> t[n] <= INT_MAX;
  @ assigns \nothing;
  @ behavior t_vide:
  @    assumes len == 0;
  @    ensures \result == -1;
  @ behavior t_max:
  @    assumes len > 0;
  @    ensures \forall integer n; 0 <= n < len ==> \result >= t[n];
  @    ensures \exists int e; 0 <= e < len && \result == t[e];
  @    ensures \result >= 0;
  @ complete behaviors;
  @ disjoint behaviors;
  @ */
int max_seq(unsigned int *t, int len) {
  if (len <= 0) return -1;
  return t[max_idx(t, len)];
}