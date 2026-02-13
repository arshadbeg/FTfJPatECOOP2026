// ACSL annotation for q2.c
/*
@requires a != NULL;
@requires n >= 0;
@requires k >= 0;
@requires k < n; // to avoid out-of-bounds at a[k+1]
@assigns a[0..k];
@ensures (\forall j. 0 <= j < k ==> 
          (a[j] <= a[j+1]) 
          || 
          (there exists m < j. a[m] > a[m+1] @old at that step but after swaps, array is partially sorted up to k)
         );
// More precisely:
// @ensures After execution, for all 0 <= i < k: a[i] <= a[i+1] does NOT necessarily hold globally, 
//         but at least one inversion (if present) between a[j] and a[j+1] for j < k is fixed.
//         Alternatively, if we want a stronger spec:
//         @ensures (\forall j. 0 <= j < k ==> \old(a[j]) > \old(a[j+1]) ==> a[j] <= a[j+1]);
// But as written, the function does a single pass of bubble sort up to k.
@ensures \forall j. 0 <= j < k ==> 
          ( (\old(a[j]) <= \old(a[j+1])) || (a[j] <= a[j+1]) );
*/

void q2(int a[], int n, int k) {
  //@ assume a != NULL && n >= 0 && k >= 0 && k < n;
  for (int j = 0; j < k; j++) {
    //@ invariant 0 <= j <= k
    if (a[j] > a[j + 1]) {
      int t = a[j];
      a[j] = a[j + 1];
      a[j + 1] = t;
      //@ assert After swap, a[j] <= a[j+1];
    }
  }
}
