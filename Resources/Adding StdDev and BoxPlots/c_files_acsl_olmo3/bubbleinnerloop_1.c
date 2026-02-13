/*
  @ requires a != NULL;
  @ requires n >= 0;
  @ ensures \forall integer i, j; 0 <= i < j < n - 1 ==> 
      (\old(a[i]) < \old(a[j])) || 
      ((\old(a[i]) >= \old(a[j])) && a[i] <= a[j]);
  // Alternatively, a weaker but more practical postcondition:
  // @ ensures The array 'a' has performed one pass of bubble sort:
  //         For all i in [0, n-2), if i+1 < n then after the loop, 
  //         a[i] <= a[i+1] is at least as true as before the call for some pairs.
  // However, ACSL does not directly express "progress" in sorting in one pass,
  // so we often just state that the array is unchanged except for some swaps.
  // If you want a stronger spec, you can say:
  // @ ensures \forall integer i; 0 <= i < n - 1 ==> 
  //         ((\old(a[i]) <= \old(a[i+1])) || (a[i] <= a[i+1]) && exists some swap);
  // But typically, we just note that the array is modified in place and some
  // adjacent pairs may be swapped if out of order.
*/
void bubbleinnerloop(int a[], int n) {
    // @ loop invariant 0 <= j < n - 1;
    // @ loop invariant \forall integer k; 0 <= k < j ==> a[k] <= a[k+1];
    // This would be true only if we keep the array sorted up to j, but this function
    // does not guarantee that at the end of the pass, so let's keep it simple.
    for (int j = 0; j < n - 1; j++) {
        if (a[j] > a[j + 1]) {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
    }
}
