/*@ requires n >= 0;
    requires \valid(v + (0..n-1)) && \valid(o + (0..n-1));
    requires \valid_function(predicate);
    assigns o[0..n-1];
    ensures 0 <= \result <= n;
    ensures \forall integer i; 0 <= i < \result ==> 0 <= o[i] < n && predicate(v[o[i]]);
    ensures \forall integer i; 0 <= i < n ==> (predicate(v[i]) ==> \exists integer j; 0 <= j < \result && o[j] == i);
*/
int index_where(int* v, int n, int* o) {
  int r = 0;
  
  /*@ loop invariant 0 <= i <= n;
      loop invariant 0 <= r <= i;
      loop invariant \forall integer k; 0 <= k < r ==> 0 <= o[k] < i && predicate(v[o[k]]);
      loop invariant \forall integer k; 0 <= k < i ==> (predicate(v[k]) ==> \exists integer j; 0 <= j < r && o[j] == k);
      loop assigns i, r, o[0..n-1];
      loop variant n - i;
  */
  for (int i = 0; i < n; i++) {
    if (predicate(v[i])) {
      o[r++] = i;
    }
  }
  return r;
}
