// ACSL annotation for min.c
/*
@requires t != NULL && n >= 0;
@ensures \result == (\min_{0 <= i < n} t[i]);
@assigns nothing;
*/

int min(int *t, int n) {
  //@ assume t != NULL && n >= 0;
  int minVal = t[0]; //@ invariant minVal == (\min_{0 <= i < i0} t[i]) for appropriate i0
  int i;
  for (i = 1; i < n; i++) {
    //@ invariant 1 <= i <= n
    //@ invariant minVal == (\min_{0 <= k < i} t[k])
    if (t[i] < minVal) {
      minVal = t[i];
    }
  }
  return minVal; //@ ensures \result == minVal;
}
