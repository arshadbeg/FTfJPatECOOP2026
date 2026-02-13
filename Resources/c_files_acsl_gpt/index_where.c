/*@
  requires \valid_read(v + (0 .. n-1));
  requires \valid(o + (0 .. n-1));
  assigns o[0 .. n-1];
  ensures 0 <= \result <= n;
  ensures (\forall integer k; 0 <= k < \result ==> predicate(v[o[k]]));
  ensures (\forall integer k; 0 <= k < n; predicate(v[k]) ==> (\exists integer j; 0 <= j < \result && o[j] == k));
*/
int index_where(int* v, int n, int* o) {
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (predicate(v[i])) {
      o[r++] = i;
    }
  }
  return r;
}

