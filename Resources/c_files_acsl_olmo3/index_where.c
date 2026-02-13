/*
  @ requires v != NULL;
  @ requires n >= 0;
  @ requires o != NULL;
  @ requires \valid(o + 0 .. o + n - 1); // or adjust if fewer matches
  @ ensures 
      \let r = \result;
      \forall integer i; 0 <= i < r ==> predicate(v[o[i]]) == 1;
      \forall integer i; r <= i < n ==> \forall integer j; 0 <= j < r ==> o[i] != o[j];
      \forall integer i; 0 <= i < n ==> 
         ((predicate(v[i]) == 1) ==> \exists integer j; 0 <= j < r && o[j] == i);
      // That is, o[0..r-1] contains all indices i in [0, n) where predicate(v[i]) is true
      // and each such i appears exactly once;
      // \result == r;
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
